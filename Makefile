# Replace 'pcd' with the exact name of your C file (e.g., if pcd.c, use pcd.o)
obj-m += ldd.o

# Detect the running kernel version and path
KDIR ?= /lib/modules/$(shell uname -r)/build

# Default target: builds the module
all:
	make -C $(KDIR) M=$(PWD) modules

# Clean target: removes build artifacts
clean:
	make -C $(KDIR) M=$(PWD) clean