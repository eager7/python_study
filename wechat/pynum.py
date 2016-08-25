#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import json
from collections import Counter
import pandas as pd
from pandas import DataFrame,Series
import matplotlib.pyplot as plt

def main():
    print 'python num test'
    with open('./resource/contact.txt', 'r') as f:
        records = json.load(f)
<<<<<<< HEAD

    dic = {}
    mlist = records[0].keys()
    for l in mlist:
        dic[l] = [r[l] for r in records]

    frame = DataFrame(dic)
    #frame.to_excel('test.xlsx')
    frame.to_csv('friend.csv', encoding='utf-8')
=======
    print len(records)
    print records[0]
    citys = [record['City'] for record in records if 'City' in record]
    #print citys
    #counts = Counter(citys)
    #for x in counts.most_common():
        #print x[0],x[1]
    print '----------------'*10

    frame = DataFrame(records)
    #print frame['City'].value_counts()
    series = frame['City'].value_counts()
    series.plot(kind='barh', rot=0)
    plt.show()
>>>>>>> 343a608dc14e508c0a08fc1a11cb230b67359d12

    sex = frame['Sex'].value_counts()
    sex.plot(kind='barh',rot=0)
    plt.show()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')