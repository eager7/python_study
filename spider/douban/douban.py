#!/usr/bin/python
# -*- coding: utf-8 -*-
import requests, re, sys
from bs4 import BeautifulSoup
from requests.adapters import HTTPAdapter
from pandas import DataFrame
reload(sys)
sys.setdefaultencoding('utf-8')  # 解决中文写入文件问题

__metaclass__ = type

# 模拟浏览器的代理设置
_user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0'
book_dic = {}

class mSpider():
    '''
    豆瓣爬虫的自定义类
    '''
    def __init__(self):
        self.url_base = 'https://book.douban.com/top250?start='
        self.my_requests = requests.Session()
        self.my_requests.keep_alive = False
        self.my_requests.mount('https://book.douban.com', HTTPAdapter(max_retries=5))
        headers = {'User-agent': _user_agent}
        self.my_requests.headers.update(headers)
        self.regular = r'<p class="pl">(\S+?).*?/.*?(\S+?).*?/.*?(\S+?).*?/.*?(\S+?).*?/.*?(\S+?)<'
        self.books = []

    def get_books(self, number_page):
        url = self.url_base + str(number_page*25)
        data = self.my_requests.get(url)
        data.encoding = 'utf-8'

        # with open('data.txt', 'w') as f:
        #    f.write(data.text)

        soup = BeautifulSoup(data.content, 'html.parser')
        table = soup.findAll('table', {"width": "100%"})  # 图书的信息是用table组织起来的,在html源码处可以看到,根据后面的变量取整个table

        for index in xrange(len(table)):  # 分析每一本书
            dic = {}
            sp = BeautifulSoup(str(table[index]))
            dic['img'] = sp.a.img['src']
            dic['book_url'] = sp.a['href']
            dic['book_name'] = sp.div.a['title']
            others = re.search(r'<p class="pl">([\s\S]*)<', str(sp.p)).group(1)
            other = others.split('/')
            if len(other) == 5:  # 表示有翻译作者
                dic['author'] = unicode(other[0], 'utf-8')
                dic['translator'] = unicode(other[1], 'utf-8')
                dic['publisher'] = unicode(other[2], 'utf-8')
                dic['date'] = unicode(other[3], 'utf-8')
                dic['price'] = unicode(other[4], 'utf-8')
            else:
                dic['author'] = ''
                dic['translator'] = unicode(other[0], 'utf-8')
                dic['publisher'] = unicode(other[1], 'utf-8')
                dic['date'] = unicode(other[2], 'utf-8')
                dic['price'] = unicode(other[3], 'utf-8')
            self.books.append(dic)


def main():
    print 'dou ban spider process'
    spider = mSpider()
    for index in xrange(10):
        spider.get_books(0)

    mlist = spider.books[0].keys()
    for l in mlist:
        book_dic[l] = [r[l] for r in spider.books]
    DataFrame(book_dic).to_csv('book.csv', encoding='utf-8')


if __name__ == '__main__':
    main()
