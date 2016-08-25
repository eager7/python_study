#!/usr/bin/env python
# -*- coding: utf-8 -*-

"This Module is a Decorator Lib"


def catch_keyboard_interrupt(fn):
    def wrapper(*args):
        try:
            return fn(*args)
        except KeyboardInterrupt:
            print 'exit process by interrupt'
            exit(0)
    return wrapper

if __name__ == '__main__':
    print "This is Test"



