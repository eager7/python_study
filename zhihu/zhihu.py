#!/usr/bin/env python
# -*- coding: utf-8 -*-
__author__ = 'pct'

from mDbg import *
from mHtmlParser import mHtmlParser
import urllib, urllib2, cookielib

values = {"username":"eager7@163.com", "password":"1197639"}
user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0'
header = {'User-Agent':user_agent, 'Referer':'http://www.zhihu.com/articles'}
url = 'https://www.zhihu.com/explore'

if __name__ == '__main__':
    cookie = cookielib.CookieJar()
    handler = urllib2.HTTPCookieProcessor(cookie)
    opener = urllib2.build_opener(handler)

    data = urllib.urlencode(values)
    request = urllib2.Request(url, data, header)
    DBG_Printf(True, request.data, request.headers)
    try:
        html = opener.open(url + '?' + data, timeout=10)
        print html.read()
    except urllib2.HTTPError as e:
        ERR_Printf(True, e.code)
    except urllib2.URLError as e:#father's except after child's except
        ERR_Printf(True, e.reason)

    for item in cookie:
        print 'Name:' + item.name
        print 'Value:' + item.value
