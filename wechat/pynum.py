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

    dic = {}
    mlist = records[0].keys()
    for l in mlist:
        dic[l] = [r[l] for r in records]

    frame = DataFrame(dic)
    #frame.to_excel('test.xlsx')
    frame.to_csv('friend.csv', encoding='utf-8')

if __name__ == '__main__':
    main()
    raw_input('entry to exit')