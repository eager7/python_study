#!/usr/bin/python
# -*- coding: utf-8 -*-

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import openpyxl

def main():
    print 'pynum test'

    s = pd.Series([1, 3, 5, np.nan,6,8])
    print s

    print '---'*10
    datas = pd.date_range('20160820', periods=6)
    print datas

    print '---' * 10
    df = pd.DataFrame(np.random.rand(6,4), index=datas, columns=list('ABCD'))
    print df
    print df.head(1)
    print df.columns
    print df.values
    print df.describe()
    df.to_excel('test.xlsx', sheet_name='Sheet1')

    print '---' * 10
    df2 = pd.DataFrame({
        'A':1,
        'B':pd.Timestamp('20160820'),
        'C':pd.Series(1,index=list(range(4)),dtype='float32'),
        'D':np.array([3]*4, dtype='int32'),
        'E':pd.Categorical(['test','train','test','train']),
        'F':'foo'
    })
    print df2
    print df2.dtypes

    print '---' * 10
    r = {i:np.random.randn() for i in range(7)}
    print r

if __name__ == '__main__':
    main()