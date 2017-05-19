#!/usr/bin/env python
# -*- coding: utf-8 -*-
import SimpleHTTPServer
import SocketServer

def main():
    PORT = 8082

    Handler = SimpleHTTPServer.SimpleHTTPRequestHandler

    httpd = SocketServer.TCPServer(("", PORT), Handler)

    print "serving at port", PORT
    httpd.serve_forever()


if __name__ == '__main__':
    print 'http server program'
    main()
