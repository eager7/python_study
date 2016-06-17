#!/usr/bin/env python
# -*- coding:utf-8 -*-

__author__ = 'changtao.pan'

from mDbg import *
import socket
import time,sys

if __name__ == '__main__':
    DBG_Printf(True, "Socket Client Program")
    i = 1
    sock = [None]*10

    for index in range(sock.__len__()):
        while True:
            try:
                sock[index] = socket.socket()
                sock[index].connect(('127.0.0.1',7878))
                NOT_Printf(True, "Connect Success:%s"%sock[index])
                sock[index].send(("Hello"))
            except Exception,e:
                WAR_Printf(True, e)
            else:
                break
            finally:
                time.sleep(2)

    time.sleep(5)

    for index in range(sock.__len__()):
        try:
            sock[index].send("I will close")
            sock[index].close()
            INF_Printf(True, "Close Success:%s"%sock[index])
        except socket.error,e:
            WAR_Printf(True, e)
        finally:
            time.sleep(2)