#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt

def main():
    print 'python test'
    x = np.linspace(0, 4*np.pi, 100)
    pl.plot(x, np.sin(x))
    plt.show()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')