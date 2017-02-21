.PHONY:modules modules_install clean

KERNELDIR=/lib/modules/`uname -r`/build
PWD:=$(shell pwd)
INSTALLDIR=/home/parallels/mycode/linux_driver
obj-m:=wq.o
modules:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

modules_install:
	cp wq.ko $(INSTALLDIR)

clean:
	rm -rf *.o *.ko *.mod.c .*.cmd .tmp_versions *.order Module.symvers
