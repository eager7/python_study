#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import json
from collections import Counter
import pandas as pd
from pandas import DataFrame, Series
import matplotlib.pyplot as plt


def main():
    print 'we_chat data visualization process'

    frame = DataFrame.from_csv('./resource/contact.csv')

    plt.figure(figsize=(6, 12))  # size of picture
    plt.subplot(2, 1, 1)    # 行，列，图像位置

    # 显示男女比例
    labels = [u'man', u'woman', u'none']  # three parts' label
    colors = ['red', 'yellowgreen', 'lightskyblue']  # three parts' color
    sizes = [l*100.0 / len(frame) for l in frame.Sex.value_counts()]
    print sizes
    patches, l_text, p_text = plt.pie(sizes, colors=colors, labels=labels,
                                      autopct='%3.1f%%',    # 圆里面的文本格式，%3.1f%%表示小数有三位，整数有一位的浮点数
                                      startangle=90,        # 起始角度，0，表示从0开始逆时针转，为第一块。一般选择从90度开始比较好看
                                      pctdistance=0.6)      # 百分比的text离圆心的距离
    [l.set_size(10) for l in l_text]    # 设置圆外部文本的大小
    [p.set_size(10) for p in p_text]    # 设置圆内部文本的大小
    plt.legend(loc='upper left')        # 显示图例

    # 显示城市比例
    plt.subplot(2, 1, 2)
    city_series = frame.City.value_counts()
    city_series.plot(kind='barh', rot=0)

    plt.show()



if __name__ == '__main__':
    main()
    # raw_input('entry to exit')