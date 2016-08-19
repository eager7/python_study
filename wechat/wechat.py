#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ssl,requests,time,re,subprocess,sys,xml.dom.minidom,os,json
__metaclass__ = type

#模拟浏览器的代理设置
user_agent = 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:47.0) Gecko/20100101 Firefox/47.0'

def ERR_Printf(x):#Red
    print "\033[31;1m" + "[ERR]", x, "\033[0m"

def DBG_Printf(x):#Blue
    print "\033[34;1m" + "[DBG]",x,"\033[0m"

def get_uuid(my_request):
    global uuid
    url = 'https://login.weixin.qq.com/jslogin'#微信网页登录地址
    params = {
        'appid':'wx782c26e4c19acffb',
        'fun':'new',
        'lang':'zh_CN',
        '_':int(time.time())
    }
    print 'get request'
    r = my_request.get(url=url, params=params)
    r.encoding = 'utf-8'#用utf8解码内容
    data = r.text
    result = re.search(r'window.QRLogin.code = (\d+); window.QRLogin.uuid = "(\S+?)"', data)
    code = result.group(1)
    uuid = result.group(2)
    if code == '200':
        return True
    else:
        ERR_Printf(code)
        return False

def get_qr_code(my_request):
    url = 'https://login.weixin.qq.com/qrcode/' + uuid
    params = {
        't':'webwx',
        '_':int(time.time()),
    }
    r = my_request.get(url=url, params=params)
    f = open('./qr_code.jpg', 'wb')#用二进制方式打开文件，并写入图片信息
    f.write(r.content)
    f.close()
    if sys.platform.find('darwin') >= 0:#darwin 是MAC平台的字符串，linux是linux2
        subprocess.call(['open', './qr_code.jpg'])#subprocess用来启动一个子进程
    else:
        subprocess.call(['xdg-open', './qr_code.jpg'])#xdg-open是linux的一个命令，可以打开很多格式的文件

def wait_scan(my_request):
    global base_uri, redirect_uri, push_uri
    url = 'https://login.weixin.qq.com/cgi-bin/mmwebwx-bin/login?tip=1&uuid=%s&_=%s'%(uuid,int(time.time()))
    while True:
        r = my_request.get(url)
        r.encoding = 'utf-8'
        print r.text
        time.sleep(1)
        result = re.search(r'window.code=(\d+);', r.text)
        code = result.group(1)
        if code == '201':
            print 'scanning success, please login'
        elif code == '200':
            print 'login...'
            result = re.search(r'window.redirect_uri="(\S+?)";',r.text)
            redirect_uri = result.group(1) + '&fun=new'
            base_uri = redirect_uri[:redirect_uri.rfind('/')]
            #push_uri与base_uri对应关系(排名分先后)(就是这么奇葩..)
            services = [
                ('wx2.qq.com', 'webpush2.weixin.qq.com'),
                ('qq.com', 'webpush.weixin.qq.com'),
                ('web1.wechat.com', 'webpush1.wechat.com'),
                ('web2.wechat.com', 'webpush2.wechat.com'),
                ('wechat.com', 'webpush.wechat.com'),
                ('web1.wechatapp.com', 'webpush1.wechatapp.com'),]
            push_uri = base_uri
            for (searchUrl, pushUrl) in services:
                if base_uri.find(searchUrl) >= 0:
                    push_uri = 'https://%s/cgi-bin/mmwebwx-bin' % pushUrl
                    break
            os.system('killall eog')
            return
        elif code == '408':
            ERR_Printf('timeout...')

def login(my_request):
    global skey, wxsid, wxuin, pass_ticket, BaseRequest
    r = my_request.get(url=redirect_uri)
    r.encoding = 'utf-8'
    doc = xml.dom.minidom.parseString(r.text)
    root = doc.documentElement

    for node in root.childNodes:
        if node.nodeName == 'skey':
            skey = node.childNodes[0].data
        elif node.nodeName == 'wxsid':
            wxsid = node.childNodes[0].data
        elif node.nodeName == 'wxuin':
            wxuin = node.childNodes[0].data
        elif node.nodeName == 'pass_ticket':
            pass_ticket = node.childNodes[0].data
    if not all((skey, wxsid, wxuin, pass_ticket)):
        return False
    BaseRequest = {
        'Uin': int(wxuin),
        'Sid': wxsid,
        'Skey': skey,
        'DeviceID': 'e000000000000000',
    }
    return True

def wechat_init(my_request):
    global ContactList, My, SyncKey
    url = (base_uri + '/webwxinit?pass_ticket=%s&skey=%s&r=%s'%(pass_ticket, skey, int(time.time())))
    params  = {'BaseRequest': BaseRequest}
    headers = {'content-type': 'application/json; charset=UTF-8'}
    r = my_request.post(url=url, data=json.dumps(params),headers=headers)
    r.encoding = 'utf-8'
    dic = r.json()
    ContactList = dic['ContactList']
    My = dic['User']
    SyncKey = dic['SyncKey']
    if dic['BaseResponse']['Ret'] != 0:
        ERR_Printf('Wechat Init Failed')
        return False
    return True

def wechat_get_contact(my_request):
    url = (base_uri + '/webwxgetcontact?pass_ticket=%s&skey=%s&r=%s'%(pass_ticket, skey, int(time.time())))
    headers = {'content-type': 'application/json; charset=UTF-8'}
    r = my_request.post(url=url,headers=headers)
    r.encoding = 'utf-8'
    dic = r.json()
    MemberList = dic['MemberList']
    SpecialUsers = ["newsapp", "fmessage", "filehelper",
                    "weibo", "qqmail", "tmessage", "qmessage",
                    "qqsync", "floatbottle", "lbsapp", "shakeapp",
                    "medianote", "qqfriend", "readerapp", "blogapp",
                    "facebookapp", "masssendapp", "meishiapp", "feedsapp",
                    "voip", "blogappweixin", "weixin", "brandsessionholder",
                    "weixinreminder", "wxid_novlwrv3lqwv11", "gh_22b87fa7cb3c",
                    "officialaccounts", "notification_messages", "wxitil", "userexperience_alarm"]
    for i in range(len(MemberList) - 1, -1, -1):#倒序遍历,不然删除的时候出问题..
        Member = MemberList[i]
        if Member['VerifyFlag'] & 8 != 0:  # 公众号/服务号
            MemberList.remove(Member)
        elif Member['UserName'] in SpecialUsers:  # 特殊账号
            MemberList.remove(Member)
        elif Member['UserName'].find('@@') != -1:  # 群聊
            MemberList.remove(Member)
        elif Member['UserName'] == My['UserName']:  # 自己
            MemberList.remove(Member)

    return MemberList

def main():

    if hasattr(ssl, '_create_unverified_context'):
        ssl._create_default_https_context = ssl._create_unverified_context
    headers = {'User-agent': user_agent}
    my_request = requests.Session()
    my_request.headers.update(headers)

    if not get_uuid(my_request):
        ERR_Printf('get uuid failed')
        return -1
    get_qr_code(my_request)
    wait_scan(my_request)
    if not login(my_request):
        ERR_Printf('Login Failed...')
    print 'Login Success'
    if not wechat_init(my_request):
        ERR_Printf('wechat_init failed')
        return
    print 'Wechat Init Success, Get Contact'
    MemberList = wechat_get_contact(my_request)
    with open('contact.txt', 'w') as f:
        f.write(json.dumps(MemberList))

    DBG_Printf("Your Friends' Number is %d"%len(MemberList))
    for Member in MemberList:
        DBG_Printf(Member['NickName'])

if __name__ == '__main__':
    print 'wechat program...'
    main()
    raw_input('Enter exit...\n')