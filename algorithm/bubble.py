#!/usr/bin/python
# -*- coding:utf-8 -*-
__author__ = 'changtao.pan'
__metaclass__ = type
import pickle
import numpy as np


def bubble(mlist):
    print 'bubble method'
    length = len(mlist)
    for index in xrange(length):
        for i in xrange(length - index - 1):
            if mlist[index] < mlist[i+index+1]:
                mlist[index], mlist[i+index+1] = mlist[i+index+1], mlist[index]


def main():
    print 'python study process'
    mlist = [1.54522364, -0.33393039, -0.09401967, -0.68175917, -1.41960901,
             -0.11638679, -1.72738972, -1.35641929, 0.11785387, 2.01162612]
    print mlist
    bubble(mlist)
    print mlist


    mlist.sort()
    mlist.reverse()
    print mlist

if __name__ == '__main__':
    main()