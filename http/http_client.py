#!/usr/bin/env python
# -*- coding: utf-8 -*-
import urllib2

def main():
    req = urllib2.Request('http://127.0.0.1:8082/test.bin')
    print req
    res_data = urllib2.urlopen(req)
    res = res_data.read()
    print res


if __name__ == '__main__':
    print 'http client program'
    main()
