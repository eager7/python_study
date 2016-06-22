#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal
import re, urllib
import requests
from subprocess import Popen,PIPE
from urllib import urlopen
from HTMLParser import HTMLParser
from mDbg import *
from pyquery import PyQuery as pq

url = "http://bbs.feng.com/thread-htm-fid-68.html"

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()

def get_capture(url):
    html = urllib.urlopen(url).read()
    #print html
    content = re.search("<title>.*</title>", html)
    print content.group()
    next_list = re.findall(r"(?<=href=\").+?(?=\")|(?<=href=\').+?(?=\')" ,html)
    print next_list

if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    signal.signal(signal.SIGINT, sigint_handler)

    get_capture(url)