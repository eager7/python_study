#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    x = np.array([[1,2,3],[4,5,6]])
    y = np.array([[6,23],[-1,7],[8,9]])
    print np.dot(x,y)

if __name__ == '__main__':
    main()
    raw_input('entry to exit')
