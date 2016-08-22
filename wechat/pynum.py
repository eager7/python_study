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
    with open('contact.txt', 'r') as f:
        records = json.load(f)
    print len(records)
    citys = [record['City'] for record in records if 'City' in record]
    print citys
    counts = Counter(citys)
    for x in counts.most_common():
        print x[0],x[1]
    print '----------------'*10

    frame = DataFrame(records)
    print frame['City'].value_counts()
    series = frame['City'].value_counts()
    series.plot(kind='barh', rot=0)
    plt.show()

if __name__ == '__main__':
    main()
    raw_input('entry to exit')