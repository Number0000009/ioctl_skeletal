obj-m := skeletal_ioctl.o

EXTRA_CFLAGS += -g -O0
KASAN_SANITIZE := y
UBSAN_SANITIZE := y

all:
	make -C /lib/modules/$$(uname -r)/build M=$(PWD) ARCH=$$(uname -m) modules
clean:
	make -C /lib/modules/$$(uname -r)/build M=$(PWD) ARCH=$$(uname -m) clean
