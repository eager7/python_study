#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal
import re
import requests
from subprocess import Popen,PIPE
from urllib import urlopen
from HTMLParser import HTMLParser
from InternetSpider.mDbg import *


url = "http://jonathan.leanote.com/post/ROS-Tutorial%E7%AC%AC%E4%BA%94%E9%83%A8%E5%88%86%EF%BC%9A%E5%86%99%E4%B8%80%E4%B8%AAPublisher%E5%92%8CSubscriber"

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()

if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    signal.signal(signal.SIGINT, sigint_handler)

    payload = {'wd':'github', 'rn':'1'}
    r = requests.get(url, params=payload)
    INF_Printf(True,"Return Value:", r.status_code)
    INF_Printf(True,"Encoding:", r.encoding)
    INF_Printf(True,"Url:", r.url)

    #DBG_Printf(True,"Return Header:", r.headers)
    #DBG_Printf(True,"Return Text:", r.text)

    link_list =re.findall(r"(?<=href=\").+?(?=\")|(?<=href=\').+?(?=\')" ,r.text)
    for url_l in link_list:
        NOT_Printf(True, url_l)
    print r.text