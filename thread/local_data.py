#!/usr/bin/python
# -*- coding:utf-8 -*-
import threading
__metaclass__ = type


global_data = threading.local()


def thread_handle():
    global_data.num = 0
    for _ in xrange(1000):
        global_data.num += 1
    print '[name:%s, num:%d]' % (threading.current_thread().getName(), global_data.num)


def main():
    print 'thread local data'
    threads = []
    for i in xrange(10):
        threads.append(threading.Thread(target=thread_handle))
        threads[i].start()

if __name__ == '__main__':
    main()
