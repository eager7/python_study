#!/usr/bin/env python
# -*- coding: utf-8 -*-
__author__ = 'pct'

from HTMLParser import HTMLParser

class mNote(HTMLParser):
    def __init__(self, url=None):
        HTMLParser.__init__(self)
        self.flag = None
        self.url = url
        self.skip = False
        self.link = []

    def handle_startendtag(self, tag, attrs):
        pass

    def handle_starttag(self, tag, attrs):  #start handle tag
        if tag == 'body':
            self.skip = True
        if self.skip and tag == 'a':
            self.flag = 'a'
            for herf, link in attrs:
                if herf == 'href':
                    if "http" in link:
                        continue
                    self.link.append(self.url+link)
        self.link = {}.fromkeys(self.link).keys() #delete same link
    def handle_endtag(self, tag):           #stop handle tag
        if tag == 'body':
            self.skip = False

    def handle_decl(self, decl):            #handle lisk <! tag
        pass

    def handle_charref(self, name):         #handle special str like &#
        pass

    def handle_data(self, data):            #handle data like <xx>data</xx>
        pass

    def handle_comment(self, data):         #handle comment
        pass

    def handle_entityref(self, name):       #handle special str like &
        pass

    def handle_pi(self, data):              #handle like <?instruction>
        pass

    def display(self):
        for link in self.link:
            print link

if __name__ == '__main__':
    print "My Html Parser"
    m = mHtmlParser("link:")
    f = open("102.html")
    m.feed(f.read())
    m.close()
