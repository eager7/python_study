#!/usr/bin/env python
__author__ = 'changtao.pan'

from mDbg import *
import socket
import time

if __name__ == '__main__':
    DBG_Printf(True, "Socket Client Program")
    sock = [None]*10
    for i in range(sock.__len__()):
        sock[i] = socket.socket()
        sock[i].connect(('127.0.0.1',7878))
        NOT_Printf(True, "Connect Success:%s"%sock[i])
        time.sleep(2)

    time.sleep(10)
    
    for s in sock:
        s.close()
        INF_Printf(True, "Close Success:%s"%s)
        time.sleep(2)