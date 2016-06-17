#!/usr/bin/env python
# -*- coding:utf-8 -*-
__author__ = 'changtao.pan'

from mDbg import *
from SocketServer import TCPServer,ThreadingMixIn,StreamRequestHandler

class Server(ThreadingMixIn,TCPServer):pass

class Handler(StreamRequestHandler):#为每个socket客户端创建一个线程
    def handle(self):
        addr = self.request.getpeername()
        NOT_Printf(True, 'Thread[%s] Got Client:%s'%(self,addr))
        #self.wfile.write('I am Server')

if __name__ == '__main__':
    DBG_Printf(True, "SocketServer Program")
    server = Server(('127.0.0.1', 7878), Handler)
    server.serve_forever()