#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mThread import mThread
import serial,time,Queue
import binascii
#---------------------------------------------------------------#
#                          Serial Setting                       #
#---------------------------------------------------------------#
SerialPort = '/dev/ttyUSB0'
SerialBaud = 115200
mQueue = Queue.Queue(maxsize=10)
#---------------------------------------------------------------#
#                          Type Defined                         #
#---------------------------------------------------------------#
E_SL_MSG_STATUS                         =   0x8000
E_SL_MSG_LOG                            =   0x8001
E_SL_MSG_GET_VERSION                    =   0x0010
E_SL_MSG_VERSION_LIST                   =   0x8010
#---------------------------------------------------------------#
#                         Class Defined                         #
#---------------------------------------------------------------#
__metaclass__ = type
class SerialMessage():
    def __init__(self, msg_type,msg_list):
        assert type(msg_list) == list
        self.msg_list = [0x01]#预定义消息起始位，起始位和结束位不会进行编码
        #预定义消息类型，长度和校验位，后面会进行编码
        message = [(msg_type<<8)&0xff,msg_type&0xff,(len(msg_list)<<8)&0xff,len(msg_list)&0xff,0x00]
        message.extend(msg_list)
        message[4] = self._chksum(message)
        self._encode(message)#编码信息
        message.append(0x03)
        self.msg_list.extend(message)

    def getdata(self):
        return self.msg_list

    def _encode(self, mlist):
        if mlist.__len__() == 0:
            return []
        index = 0
        while True:
            try:
                if mlist[index] < 0x10:#如果一个信息a小于0x10，那么将它转换为0x02和a|0x10
                    temp = mlist[index]
                    mlist.insert(index+1, temp|0x10)
                    mlist[index] = 0x02
                    index += 2
                else:
                    index += 1
            except:#遍历完引发异常
                break

    def _chksum(self, mlist):#将消息中除了起始和结束外的所以数据依次进行异或运算，得到校验值
        chksum = 0
        for s in mlist:
            chksum = chksum ^ s
        return chksum

    def show(self):
        for s in self.msg_list:
            print('0x%02x,')%s,
        print ''

    @staticmethod
    def display(mlist):#静态方法，通过类名调用，用来显示解码后消息内容
        for s in mlist:
            print('0x%02x,')%s,
        print ''

    @staticmethod
    def decode(mlist):#静态方法，通过类名调用，用来解码串口收到的数据
        assert type(mlist) == list
        for index, l in enumerate(mlist):
            if l == 0x02:
                del mlist[index]
                mlist[index] = mlist[index]&0x0f
        return mlist[:]

class mSerial(mThread):
    def __init__(self, com=SerialPort, baud=SerialBaud, name=None):
        super(mSerial,self).__init__(name=name)
        self.read_msg = []
        self.start_flag = False
        self.serial = None
        if not self._open(com, baud):
            self.Print("Can't Open Serial")
            exit(1)
        print 'Serial Init Success'

    def _open(self, com, baud):
        try:
            self.serial = serial.Serial(port=com,baudrate=baud,bytesize=8,
                    parity='N',stopbits=1,rtscts=True,dsrdtr=True)
            return True
        except Exception as e:
            self.Print(e)
            return False

    def send(self, mlist):
        assert type(mlist) == list
        try:
            n = 0
            for l in mlist:
                n += self.serial.write(chr(l))#串口只能发送char型数据
            self.serial.flush()
            return n
        except serial.SerialException as e:
            self.Print(e)
            return -1

    def run(self):
        global mQueue
        while self.thread_state:
            c = ord(self.serial.read())#将char型数据转回int
            if c == '':
                continue
            if (c == 0x01) and (self.start_flag == False):#串口消息已0x01作为起始
                self.read_msg.append(c)
                self.start_flag = True
            elif (self.start_flag == True) and (c != 0x03):
                self.read_msg.append(c)
            elif c == 0x03:#串口消息已0x03作为结束
                self.read_msg.append(c)
                SLMsg = SerialMessage.decode(self.read_msg)#将信息进行解码
                SerialMessage.display(SLMsg)
                mQueue.put(SLMsg)#发送到消息队列，由另外线程处理数据

    def close(self):
        self.stop()
        self.serial.close()

    def Print(self, x):
        print "\033[31;1m" + "[ERR]", x, "\033[0m"

class SerialHandler(mThread):#串口数据处理线程，从队列中取数据进行处理
    def __init__(self, thread_info=None, name=None):
        super(SerialHandler,self).__init__(thread_info,name)

    def run(self):
        global mQueue
        while self.thread_state:
            print 'waiting queue...'
            msg = mQueue.get()
            msg_type = msg[1]<<8 | msg[2]
            if msg_type == E_SL_MSG_GET_VERSION:
                print 'Client Request Version'
                #self.thread_info.send(SerialMessage(0x8010,[]).getdata())

if __name__ == '__main__':
    print 'python serial test'

    Serial = mSerial(com=SerialPort, baud=SerialBaud, name='SerialThread')
    Serial.start()
    SerialHandle = SerialHandler(thread_info = None, name = 'SerialHandle')
    SerialHandle.start()
    time.sleep(2)
    Serial.send(SerialMessage(0x0010,[]).getdata())
    time.sleep(5)
    Serial.close()
    SerialHandle.stop()





