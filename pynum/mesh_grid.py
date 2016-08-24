#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    points = np.arange(-5,5,0.01)
    xs, ys = np.meshgrid(points,points)
    z = np.sqrt(xs**2 + ys**2)
    plt.imshow(z)
    plt.show()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')