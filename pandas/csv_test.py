#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
from pandas import DataFrame,Series
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    arrs = np.random.randn(5,5)
    print arrs
    data = DataFrame(arrs)
    print data
    data.to_csv('test.csv')

if __name__ == '__main__':
    main()
    raw_input('entry to exit')
