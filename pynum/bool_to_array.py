#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    xarr = np.array([1.1,1.2,1.3,1.4,1.5])
    yarr = np.array([2.1,2.2,2.3,2.4,2.5])
    cond = np.array([True,False,True,True,False])

    print [x if z else y for x,y,z in zip(xarr,yarr,cond)]
    print np.where(cond,xarr,yarr)

    arr = np.random.randn(4,4)
    print arr
    arr2 = np.where(arr > 0, 2, -2)
    print arr2

if __name__ == '__main__':
    main()
    raw_input('entry to exit')