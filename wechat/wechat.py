#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ssl,requests,time,re,subprocess,sys,xml.dom.minidom,os,json,threading
import numpy as np
import pandas as pd
from pandas import Series,DataFrame
from mLib.mThread import mThread
from mLib.mDbg import *
__metaclass__ = type

#模拟浏览器的代理设置
_user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0'
_appid = 'wx782c26e4c19acffb'#微信网页版的APPID
_lang = 'zh_CN'#语言
_services = [#push_uri与base_uri对应关系，代表不同登录环境下的不同链接
    ('wx2.qq.com', 'webpush2.weixin.qq.com'),
    ('qq.com', 'webpush.weixin.qq.com'),
    ('web1.wechat.com', 'webpush1.wechat.com'),
    ('web2.wechat.com', 'webpush2.wechat.com'),
    ('wechat.com', 'webpush.wechat.com'),
    ('web1.wechatapp.com', 'webpush1.wechatapp.com'),]
_SpecialUsers = [#微信中的特殊联系人信息
    "newsapp", "fmessage", "filehelper",
    "weibo", "qqmail", "tmessage", "qmessage",
    "qqsync", "floatbottle", "lbsapp", "shakeapp",
    "medianote", "qqfriend", "readerapp", "blogapp",
    "facebookapp", "masssendapp", "meishiapp", "feedsapp",
    "voip", "blogappweixin", "weixin", "brandsessionholder",
    "weixinreminder", "wxid_novlwrv3lqwv11", "gh_22b87fa7cb3c",
    "officialaccounts", "notification_messages", "wxitil", "userexperience_alarm"]

class mWechat(mThread):
    def __init__(self, thread_info = None, name = None):
        super(mWechat,self).__init__(thread_info,name)
        if hasattr(ssl, '_create_unverified_context'):
            ssl._create_default_https_context = ssl._create_unverified_context
        headers = {'User-agent': _user_agent}
        self.my_request = requests.Session()
        self.my_request.headers.update(headers)
        self.uuid = ''              #get_uuid will get a value

        self.redirect_uri = ''      #包含ticket的链接
        self.base_uri = ''          #从redirect_uri中解析出来的基础url
        self.push_uri = ''          #根据表格重组的push链接
        self.skey = ''              #下面四个为微信登录成功后返回的四个关键参数
        self.wxsid = ''
        self.wxuin = ''
        self.pass_ticket = ''
        self.BaseRequest = {}       #微信初始化和通信时的参数，由上面四个参数组成
        self.Dictionary = {}        #微信初始化完成后返回的帐号信息

        self.User = {}              #从帐号信息解析出来的用户个人信息
        self.SyncKey = {}           #从帐号信息中解析出来的同步密钥
        self.synckey = {}           #根据SyncKey重组的同步密钥
        self.MemberCount = 0        #联系人个数
        self.MemberList = {}        #联系人列表

    def run(self):
        DBG_Printf('Start Running')
        if not self.get_uuid():
            ERR_Printf('get uuid failed')
            return -1
        self.get_qr_code()
        self.wait_scan()
        if not self.login():
            ERR_Printf('Login Failed...')

        print 'Login Success'
        if not self.wechat_init():
            ERR_Printf('wechat_init failed')
            return
        print 'Wechat Init Success, Get Contact'
        self.wechat_get_contact()
        with open('contact.csv', 'w') as f:
            f.write(json.dumps(self.MemberList))
        DBG_Printf("Your Friends' Number is %d"%len(self.MemberList))

        self.down_image()
        #threading.Thread(target=self.heart_beat)

    def heart_beat(self):
        while True:
            if self.sync_check() != '0':
                self.webwxsync()
            time.sleep(5)

    def get_uuid(self):
        url = 'https://login.weixin.qq.com/jslogin'#微信网页登录地址
        params = {
            'appid':_appid,
            'fun':'new',
            'lang':_lang,
            '_':int(time.time())
        }
        print 'get request'
        data = self.my_request.get(url=url, params=params)
        data.encoding = 'utf-8'#用utf8解码内容
        data = data.text
        result = re.search(r'window.QRLogin.code = (\d+); window.QRLogin.uuid = "(\S+?)"', data)
        code = result.group(1)
        self.uuid = result.group(2)
        if code == '200':
            return True
        else:
            ERR_Printf(code)
            return False

    def get_qr_code(self):
        url = 'https://login.weixin.qq.com/qrcode/' + self.uuid
        params = {
            't':'webwx',
            '_':int(time.time()),
        }
        r = self.my_request.get(url=url, params=params)
        with open('./qr_code.jpg', 'wb') as f:#用二进制方式打开文件，并写入图片信息
            f.write(r.content)
        if sys.platform.find('darwin') >= 0:# darwin 是MAC平台的字符串，linux是linux2
            subprocess.call(['open', './qr_code.jpg'])# subprocess用来启动一个子进程
        else:
            subprocess.call(['xdg-open', './qr_code.jpg'])# xdg-open是linux的一个命令，可以打开很多格式的文件

    def wait_scan(self):
        tip = 1# 1---not scan, 0---scanned
        while True:
            url = 'https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?tip=%d&uuid=%s&_=%s'%(tip,self.uuid,int(time.time()))
            data = self.my_request.get(url)
            data.encoding = 'utf-8'
            time.sleep(tip)
            result = re.search(r'window.code=(\d+);', data.text)
            code = result.group(1)
            if code == '201':   # 扫描成功
                print 'scanning success, please login'
                tip = 0
            elif code == '200': # 确认登录
                print 'login...'
                result = re.search(r'window.redirect_uri="(\S+?)";',data.text)
                '''
                此处返回值为：
                window.redirect_uri="https://wx2.qq.com/cgi-bin/mmwebwx-bin/webwxnewloginpage?ticket=Axa8pgsqi9XNOFk1RPwCnos6@qrticket_0&uuid=IdEAO5hslQ==&lang=zh_CN&scan=1471596025"
                '''
                self.redirect_uri = result.group(1) + '&fun=new'# 组成login方法中的链接地址
                self.push_uri = self.base_uri = self.redirect_uri[:self.redirect_uri.rfind('/')]
                for (searchUrl, pushUrl) in _services:
                    if self.base_uri.find(searchUrl) >= 0:
                        self.push_uri = 'https://%s/cgi-bin/mmwebwx-bin' % pushUrl
                        break
                os.system('killall eog')
                return
            elif code == '408':
                ERR_Printf('timeout...')

    def login(self):
        data = self.my_request.get(url=self.redirect_uri)
        data.encoding = 'utf-8'
        doc = xml.dom.minidom.parseString(data.text)
        root = doc.documentElement

        for node in root.childNodes:
            if node.nodeName == 'skey':
                self.skey = node.childNodes[0].data
            elif node.nodeName == 'wxsid':
                self.wxsid = node.childNodes[0].data
            elif node.nodeName == 'wxuin':
                self.wxuin = node.childNodes[0].data
            elif node.nodeName == 'pass_ticket':
                self.pass_ticket = node.childNodes[0].data
        if all((self.skey, self.wxsid, self.wxuin, self.pass_ticket)):
            self.BaseRequest = {
                'Uin':  int(self.wxuin),
                'Sid':  self.wxsid,
                'Skey': self.skey,
                'DeviceID': 'e000000000000000',
            }
            return True
        else:
            return False

    def wechat_init(self):
        url = (self.base_uri + '/webwxinit?pass_ticket=%s&skey=%s&r=%s'%(self.pass_ticket, self.skey, int(time.time())))
        params  = {'BaseRequest': self.BaseRequest}
        headers = {'content-type': 'application/json; charset=UTF-8'}
        data = self.my_request.post(url=url, data=json.dumps(params),headers=headers)
        data.encoding = 'utf-8'
        dic = data.json()
        self.User = dic['User']
        self.SyncKey = dic['SyncKey']
        # synckey for synccheck
        self.synckey = '|'.join(
            [str(keyVal['Key']) + '_' + str(keyVal['Val']) for keyVal in self.SyncKey['List']])
        if dic['BaseResponse']['Ret'] != 0:
            ERR_Printf('Wechat Init Failed')
            return False
        return True

    def wechat_get_contact(self):
        url = (self.base_uri + '/webwxgetcontact?pass_ticket=%s&skey=%s&r=%s'%(self.pass_ticket, self.skey, int(time.time())))
        headers = {'content-type': 'application/json; charset=UTF-8'}
        data = self.my_request.post(url=url,headers=headers)
        data.encoding = 'utf-8'
        dic = data.json()
        self.MemberCount = dic['MemberCount']
        self.MemberList = dic['MemberList']

        for i in range(len(self.MemberList) - 1, -1, -1):       # 倒序遍历,不然删除的时候出问题
            member = self.MemberList[i]
            if member['VerifyFlag'] & 8 != 0:                   # 公众号/服务号
                self.MemberList.remove(member)
            elif member['UserName'] in _SpecialUsers:           # 特殊账号
                self.MemberList.remove(member)
            elif member['UserName'].find('@@') != -1:           # 群聊
                self.MemberList.remove(member)
            elif member['UserName'] == self.User['UserName']:   # 自己
                self.MemberList.remove(member)

    def sync_key(self):
        SyncKeyItems = ['%s_%s' % (item['Key'], item['Val']) for item in self.SyncKey['List']]
        SyncKeyStr = '|'.join(SyncKeyItems)
        return SyncKeyStr

    def sync_check(self):
        url = self.push_uri + '/synccheck?'
        params = {
            'skey':         self.BaseRequest['Skey'],
            'sid':          self.BaseRequest['Sid'],
            'uin':          self.BaseRequest['Uin'],
            'deviceId':     self.BaseRequest['DeviceID'],
            'synckey':      self.sync_key(),
            'r':            int(time.time()), }
        r = self.my_request.get(url=url,params=params)
        r.encoding = 'utf-8'
        data = r.text
        regx = r'window.synccheck={retcode:"(\d+)",selector:"(\d+)"}'
        pm = re.search(regx, data)
        selector = pm.group(2)
        return selector

    def webwxsync(self):
        global SyncKey
        url = self.base_uri + '/webwxsync?lang=zh_CN&skey=%s&sid=%s&pass_ticket=%s'% \
                    ( self.BaseRequest['Skey'], self.BaseRequest['Sid'], self.urllib.quote_plus(self.pass_ticket))
        params = { 'BaseRequest': self.BaseRequest, 'SyncKey': SyncKey, 'rr': ~int(time.time()), }
        r = self.my_request.post(url=url, data=json.dumps(params))
        r.encoding = 'utf-8'
        dic = r.json()
        SyncKey = dic['SyncKey']
        if dic['BaseResponse']['Ret'] != 0:
            ERR_Printf('Wechat Init Failed')
            return False
        return True

    def down_image(self):
        index = 0
        for member in self.MemberList:
            index += 1
            name = './'+member['UserName']+'.jpg'
            image_url = 'https://wx.qq.com'+member['HeadImgUrl']
            r = self.my_request.get(url=image_url,headers={'User-agent': _user_agent})
            with open(name, 'wb') as f:
                f.write(r.content)
                print 'Download %d picture finished'%index

def main():
    print 'wechat program...'
    we = mWechat(name='wechat')
    we.start()

if __name__ == '__main__':
    #main()

    if True:
        arr = np.array(['abcd'])
        dic = {'a':1,'b':2}
        df = pd.DataFrame(dic)
        df.to_csv('./resource/test.csv')

    raw_input('Enter exit...\n')