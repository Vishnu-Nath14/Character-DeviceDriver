#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/uaccess.h>
#include <linux/string.h>

#define DEV_MEM_SIZE 512

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Pseudo Character Device Driver Example");

char device_buffer[DEV_MEM_SIZE];

struct cdev my_cdev;
dev_t device_number;

static ssize_t pcd_read(struct file *file_pointer,
                        char __user *user_space_buffer,
                        size_t count,
                        loff_t *offset)
{
    char msg[] = "U are reading a group of bytes from the kernel\n";
    size_t len = strlen(msg);

    if (*offset >= len) {
        return 0;
    }

    if (count > len - *offset) {
        count = len - *offset;
    }

    if (copy_to_user(user_space_buffer, msg + *offset, count) != 0) {
        return -EFAULT;
    }

    *offset += count;
    return count;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read  = pcd_read,
};

static struct class *pcd_class;
static struct device *pcd_device;

static int __init entry(void)
{
    int ret;

    pr_info("PCD Driver: Initializing module...\n");

    ret = alloc_chrdev_region(&device_number, 0, 1, "pcd");
    if (ret < 0) {
        pr_err("PCD Driver: Allocation of device number failed (%d)\n", ret);
        return ret;
    }
    pr_info("PCD Driver: Allocated Major = %d, Minor = %d\n", MAJOR(device_number), MINOR(device_number));

    cdev_init(&my_cdev, &fops);
    my_cdev.owner = THIS_MODULE;

    ret = cdev_add(&my_cdev, device_number, 1);
    if (ret < 0) {
        pr_err("PCD Driver: cdev_add failed (%d)\n", ret);
        goto unreg_chrdev;
    }

    pcd_class = class_create("pcd_class");
    if (IS_ERR(pcd_class)) {
        pr_err("PCD Driver: Class creation failed\n");
        ret = PTR_ERR(pcd_class);
        goto del_cdev;
    }

    pcd_device = device_create(pcd_class, NULL, device_number, NULL, "pcd");
    if (IS_ERR(pcd_device)) {
        pr_err("PCD Driver: Device creation failed\n");
        ret = PTR_ERR(pcd_device);
        goto destroy_class;
    }

    pr_info("PCD Driver: Device created successfully at /dev/pcd\n");
    return 0;

destroy_class:
    class_destroy(pcd_class);
del_cdev:
    cdev_del(&my_cdev);
unreg_chrdev:
    unregister_chrdev_region(device_number, 1);
    return ret;
}

static void __exit out(void)
{
    pr_info("PCD Driver: Cleaning up module...\n");

    device_destroy(pcd_class, device_number);
    class_destroy(pcd_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(device_number, 1);

    pr_info("PCD Driver: Module unloaded cleanly\n");
}

module_init(entry);
module_exit(out);