#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal,sys
import re, bs4
import requests
from mDbg import *

url = "http://bbs.feng.com/thread-htm-fid-68.html"
url_1024 = "http://1024.hegongchang.red/pw/thread.php?fid=17"
url_test = "http://www.54new.com/index.html"

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()

def get_capture(url):
    html = requests.get(url)
    link_list = re.findall(r"(<a href.*onclick.*</a>)" ,html.text)
    #link_list = re.findall(r"")
    for url_l in link_list:
        rel, err = re.subn(r".*</em>", "", url_l)
        rel, err = re.subn(r".*<a href=", "", rel)
        rel, err = re.subn(r".*title.*", "", rel)
        rel, err = re.subn(r".*style.*", "", rel)
        #rel, err = re.subn(r"onclick=.*", "", rel)
        NOT_Printf(True, rel)

def get1024_txt(url):
    resp = requests.get(url)
    soup = bs4.BeautifulSoup(resp.text)
    links = [a.attrs.get('href') for a in soup.select('dev.ui stackable grid a[href^*]')]
    for url_l in links:
        print url_l


if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    reload(sys)
    sys.setdefaultencoding("utf-8")
    signal.signal(signal.SIGINT, sigint_handler)

    #get_capture(url)
    get1024_txt(url_test)