#!/usr/bin/env python
__author__ = 'changtao.pan'
__metaclass__ = type

import time
from ctypes import *

def main():
    print "python eyesight test"
    start = time.clock()
    #dll = cdll.LoadLibrary('./libeyeSight.so')
    print time.clock() - start

    #dll.eyeSight.createEngineByConfig()

if __name__ == '__main__':
    main()

