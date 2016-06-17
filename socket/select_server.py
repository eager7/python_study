#!/usr/bin/env python
__author__ = 'changtao.pan'

from mDbg import *
import select, socket,time

if __name__ == '__main__':
    DBG_Printf(True, "Socket Select Server Program")
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    sock.bind(('127.0.0.1', 7878))
    sock.listen(5)
    inputs = [sock]

    while True:
        rs, ws, es = select.select(inputs, [], [])
        for r in rs:
            if r is sock:
                cli, addr = sock.accept()
                NOT_Printf(True, ("Client Connected:", addr))
                inputs.append(cli)
            else:
                try:
                    data = r.recv(1024)
                    disconnect = not data
                except socket.error:
                    disconnect = True

                if disconnect:
                    WAR_Printf(True, (r.getpeername(),"is Disconnected"))
                    r.close()
                    inputs.remove(r)
                else:
                    INF_Printf(True, "Recv Data:%s"%data)
                    time.sleep(1)
