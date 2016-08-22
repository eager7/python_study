#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'pct'

import numpy as np
import pandas as pd
import pylab as pl
import matplotlib.pyplot as plt
from scipy import signal

def main():
    print 'python speedup'
    t = np.linspace(0, 10, 100)
    x = signal.chirp(t, 5, 10, 30)
    pl.plot(t, x)
    pl.show()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')