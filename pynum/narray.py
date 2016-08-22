#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    a = np.fromfunction(lambda x,y:(x+1)*(y+1), (9,9))
    print a
    print '***'*10
    print a[0, 3:5]
    print '***'*10
    print a[4:, 4:]

if __name__ == '__main__':
    main()
    raw_input('entry to exit')