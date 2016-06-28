#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal,sys
import re, bs4
import requests
from mHtmlParser import mHtmlParser

from mDbg import *

reload(sys)
sys.setdefaultencoding('utf8')

url = "https://1024coder.com"
url2 = "http://bbs.feng.com/thread-htm-fid-482.html/"

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()


if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    signal.signal(signal.SIGINT, sigint_handler)

    html = requests.get(url2)
    mParser = mHtmlParser(url2)
    mParser.feed(html.text)
    mParser.close()
    mParser.display()