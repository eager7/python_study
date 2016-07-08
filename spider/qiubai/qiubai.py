#!/usr/bin/env python
# -*- coding: utf-8 -*-
__author__ = 'pct'

import urllib, urllib2, cookielib, re

page = 1
url = 'http://www.qiushibaike.com/hot/page/' + str(page)
user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0'
header = {'User-Agent':user_agent, 'Referer':'http://www.zhihu.com/articles'}

if __name__ == '__main__':
    try:
        request = urllib2.Request(url, headers=header)
        html = urllib2.urlopen(request, timeout=10)
        content = html.read().decode('utf-8')
        pattern = re.compile(r'<div.*?author.*?">.*?<a.*?<img.*?<h2>'+
                             r'(.*?)'+
                             r'</h2>.*?<div.*?content">'+
                             r'(.*?)'+
                             r'</div>'
                             , re.S)
        items = pattern.findall(content)
        for item in items:
            pass
            #print item[0]
            #print item[1].replace('<br/>',' ')

        pattern_pic = re.compile(r'<div class="thumb">.*?<img src="(.*?)" alt=.*?>', re.S)
        pics = pattern_pic.findall(content)
        for pic in pics:
            print pic

    except urllib2.HTTPError as e:
        print e.code
    except urllib2.URLError as e:#father's except after child's except
        print e.reason

