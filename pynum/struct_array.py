#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    person_type = np.dtype({
        'names':['name','age','weight'],
        'formats':['S32','i','f']},align=True)#align表示内存对齐，可以用于其他程序读取

    a = np.array([('Zhang',32,75.5),('Pan',28,71.0)],dtype=person_type)
    print a
    print a.dtype
    print a['name']
    print a.flags

if __name__ == '__main__':
    main()
    raw_input('entry to exit')