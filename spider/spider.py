#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal
import requests,re

from mDbg import *

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()

if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    signal.signal(signal.SIGINT, sigint_handler)

    url = "http://www.baidu.com"
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