#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ssl,requests,time
__metaclass__ = type

user_agent = '''#模拟浏览器的代理设置
Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_2) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/44.0.2403.125 Safari/537.36
'''

def get_uuid(my_request):
    global uuid
    url = 'https://login.weixin.qq.com/jslogin'#微信网页登录地址
    params = {
        'appid':'wx782c26e4c19acffb',
        'fun':'new',
        'lang':'zh_CN',
        '_':int(time.time())
    }
    r = my_request.get(url=url, params=params)
    r.encoding()
    data = r.text
    print data

def main():

    if hasattr(ssl, '_create_unverified_context'):
        ssl._create_default_https_context = ssl._create_unverified_context
    headers = {'User-agent': user_agent}
    my_request = requests.Session()
    my_request.headers.update(headers)



if __name__ == '__main__':
    print 'wechat program...'
    main()
    raw_input('Enter exit...\n')