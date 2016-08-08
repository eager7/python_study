#!/usr/bin/python

import binascii

if __name__ == '__main__':
    print 'hello world'
    a = 120
    print bytes(a)
    print str(a)

    print bin(a)
    print '%c'%a
    print chr(a)

    b = 'x'

    print ord(b)
