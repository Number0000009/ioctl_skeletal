# ioctl_skeletal
boilerplate IOCTL module

# how-to
    insmod skeletal_ioctl.ko
    mount -t debugfs none /sys/kernel/debug
    cat /sys/kernel/debug/skeletal_ioctl/version
    rmmod skeletal_ioctl
