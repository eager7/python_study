#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys

"This Module is a Dbg Lib"
def DBG_Printf(x, flag=True):#Blue
    if flag:
        print "\033[34;1m" + "[DBG]", x, "\033[0m"
def INF_Printf(x, flag=True):#Yellow
    if flag:
        print "\033[33;1m" + "[INF]", x, "\033[0m"
def NOT_Printf(x, flag=True):#Green
    if flag:
        print "\033[32;1m" + "[NOT]", x, "\033[0m"
def WAR_Printf(x, flag=True):#Purple
    if flag:
        print "\033[35;1m" + "[WAR]", x, "\033[0m"
def ERR_Printf(x, flag=True):#Red
    if flag:
        print "\033[31;1m" + "[ERR]", x, "\033[0m"

if __name__ == '__main__':
    DBG_Printf("This is mDbg Test")
    INF_Printf("This is mDbg Test")
    NOT_Printf("This is mDbg Test")
    WAR_Printf("This is mDbg Test")
    ERR_Printf("This is mDbg Test")


