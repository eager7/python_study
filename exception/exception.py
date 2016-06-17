#!/usr/bin/env python
__author__ = 'changtao.pan'

import exceptions
from mDbg import *

def my_except():
    try:
        x = input(" Input first number:")
        y = input(" Input second number:")
        DBG_Printf(True, x / y)
    except (ZeroDivisionError, TypeError, NameError, Exception), e:
        ERR_Printf(True, e)
    else:
        NOT_Printf(True, "Good, I get you")
    finally:
        INF_Printf(True, "clean up")

class MuffCalculator:
    muffled = False
    def calc(self, expr):
        try:
            return eval(expr)
        except ZeroDivisionError:
            if self.muffled:
                print "Division by zero is illegal"
            else:
                raise
        except TypeError:
            if self.muffled:
                print "That's wasn't a number, was it?"
            else:
                raise













if __name__ == '__main__':
    DBG_Printf(True, "exception test program")
    my_except()
    calclator = MuffCalculator()
    ret = calclator.calc('10/5')
    print ret
    calclator.muffled = True
    ret = calclator.calc('10/0')