#!/usr/bin/env python
# -*- coding: utf-8 -*-

import signal
import requests

from mDbg import *

def sigint_handler(signum,frame):
    print "main-thread exit"
    sys.exit()

if __name__ == '__main__':
    DBG_Printf(True, "My First Spider Program")
    signal.signal(signal.SIGINT, sigint_handler)

    url = "http://www.baidu.com"
    r = requests.get(url)
    print r.text