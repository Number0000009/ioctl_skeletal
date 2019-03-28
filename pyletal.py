#!/usr/bin/env python3

import skeletal

def main():
    f = skeletal.Skeletal()

    arg = f.call(f.IOC_CALL1N)
    print(hex(arg))

    arg = f.call(f.IOC_CALL2N)
    print(hex(arg))

    arg = f.call(f.IOC_CALL3N)
    print(hex(arg))

    arg = f.call(f.IOC_CALL1R)
    print(hex(arg))

    arg = f.call(f.IOC_CALL2R)
    print(hex(arg))

    arg = f.call(f.IOC_CALL3R)
    print(hex(arg))

    arg = f.call(f.IOC_CALL1W)
    print(hex(arg))

    arg = f.call(f.IOC_CALL2W)
    print(hex(arg))

    arg = f.call(f.IOC_CALL3W)
    print(hex(arg))

    arg = f.call(f.IOC_CALL1RW)
    print(hex(arg))

    arg = f.call(f.IOC_CALL2RW)
    print(hex(arg))

    arg = f.call(f.IOC_CALL3RW)
    print(hex(arg))

if __name__ == '__main__':
    main()
