#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt
import time,math

def main():
    print 'python test'
    x = [i*0.001 for i in xrange(1000000)]
    start = time.clock()
    for i,t in enumerate(x):
        x[i] = math.sin(t)
    print 'math sin:', time.clock() - start
    print type(x[0])

    x = [i*0.001 for i in xrange(1000000)]
    start = time.clock()
    x = [math.sin(t) for t in x]
    print 'math sin []:', time.clock() - start
    print type(x[0])

    x = [i*0.001 for i in xrange(1000000)]
    x = np.array(x)
    start = time.clock()
    np.sin(x,x)
    print 'np sin:', time.clock() - start
    print type(x[0])
    print type(x.item(1))

    x = [i*0.001 for i in xrange(1000000)]
    start = time.clock()
    for index, t in enumerate(x):
        x[index] = np.sin(t)
    print 'np enum sin:', time.clock() - start
    print type(x[0])


if __name__ == '__main__':
    main()
    raw_input('entry to exit')