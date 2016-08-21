#!/usr/bin/python
# -*- coding:utf-8 -*-

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    print 'pynum picture test'
    ts = pd.Series(np.random.randn(1000), index=pd.date_range('1/1/2000',periods=1000))
    ts = ts.cumsum()
    ts.plot()
    raw_input('entry to next')

    df = pd.DataFrame(np.random.randn(1000,4), index=ts.index,columns=list('ABCD'))
    df = df.cumsum()
    plt.figure()
    df.plot()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')