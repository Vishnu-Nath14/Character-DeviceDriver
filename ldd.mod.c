#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9f222e1e, "alloc_chrdev_region" },
	{ 0xd2554727, "cdev_init" },
	{ 0xdb375fb3, "cdev_add" },
	{ 0x326b4c7f, "class_create" },
	{ 0x160b81b4, "device_create" },
	{ 0xd272d446, "__x86_return_thunk" },
	{ 0x2e921116, "cdev_del" },
	{ 0x0bc5fb0d, "unregister_chrdev_region" },
	{ 0x07a5cde6, "class_destroy" },
	{ 0xbd03ed67, "__ref_stack_chk_guard" },
	{ 0x5cb46e6d, "validate_usercopy_range" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0x092a35a2, "_copy_to_user" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xd17123e4, "device_destroy" },
	{ 0xd272d446, "__fentry__" },
	{ 0xe8213e80, "_printk" },
	{ 0xd954c786, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x9f222e1e,
	0xd2554727,
	0xdb375fb3,
	0x326b4c7f,
	0x160b81b4,
	0xd272d446,
	0x2e921116,
	0x0bc5fb0d,
	0x07a5cde6,
	0xbd03ed67,
	0x5cb46e6d,
	0xa61fd7aa,
	0x092a35a2,
	0xd272d446,
	0xd17123e4,
	0xd272d446,
	0xe8213e80,
	0xd954c786,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"alloc_chrdev_region\0"
	"cdev_init\0"
	"cdev_add\0"
	"class_create\0"
	"device_create\0"
	"__x86_return_thunk\0"
	"cdev_del\0"
	"unregister_chrdev_region\0"
	"class_destroy\0"
	"__ref_stack_chk_guard\0"
	"validate_usercopy_range\0"
	"__check_object_size\0"
	"_copy_to_user\0"
	"__stack_chk_fail\0"
	"device_destroy\0"
	"__fentry__\0"
	"_printk\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "BEEDBCF8B9DC04D36EB4805");
