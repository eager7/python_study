#!/usr/bin/env python
# -*- coding: utf-8 -*-

"This Module is a Decorator Lib"


def catch_keyboard_interrupt(callback=None):
    def decorator(fn):
        def wrapper(*args):
            try:
                return fn(*args)
            except KeyboardInterrupt:
                print 'exit process by key interrupt'
                if callback:
                    callback()
                exit(0)
        return wrapper
    return decorator


@catch_keyboard_interrupt
def main():
    print "This is Test"
    while True:
        pass

if __name__ == '__main__':
    main()



