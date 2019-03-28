import os, sys
from fcntl import ioctl

class IOC:

    call_number = -1
    dir = -1
    size = -1

    def __init__(self, call_number, dir, size = 0):
        self.call_number = call_number
        self.dir = dir
        self.size = size


class Skeletal:

    fd = 0

    _IO = 0
    _IOW = 1
    _IOR = 2
    _IOWR = _IOW | _IOR

    IOCIO = 0xaf

    IOC_CALL1N = IOC(0x00, _IO)
    IOC_CALL2N = IOC(0x01, _IO)
    IOC_CALL3N = IOC(0x02, _IO, 0)

    IOC_CALL1R = IOC(0x03, _IOR, 8)
    IOC_CALL2R = IOC(0x04, _IOR, 8)
    IOC_CALL3R = IOC(0x05, _IOR, 8)

    IOC_CALL1W = IOC(0x06, _IOW, 8)
    IOC_CALL2W = IOC(0x07, _IOW, 8)
    IOC_CALL3W = IOC(0x08, _IOW, 8)

    IOC_CALL1RW = IOC(0x09, _IOWR, 8)
    IOC_CALL2RW = IOC(0x0a, _IOWR, 8)
    IOC_CALL3RW = IOC(0x0b, _IOWR, 8)

    def __init__(self):
        self.fd = os.open("/dev/skeletal", os.O_RDWR)

    def __del__(self):
        os.close(self.fd)

    def call(self, ioc):
        arg = -1

        ioctl(self.fd, (ioc.dir << 30) | (ioc.size << 16) | (self.IOCIO << 8) | ioc.call_number, arg)
        return arg
