#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mThread import mThread
import serial,time,Queue
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
    def __init__(self, type=0, data=None):
        self.message = [0x01]
        if data == None:
            message = [(type<<8)&0xff,type&0xff,0x00,0x00,0x00]
        else:
            length = len(data)
            message = [(type<<8)&0xff,type&0xff,(length<<8)&0xff,length&0xff,0x00]
            message.extend(data)
        message[4] = self.__chksum__(message)
        self.__encode__(message)
        message.append(0x03)
        self.message.extend(message)

    def getdata(self):
        return self.message

    def __encode__(self, list):
        if list == None:
            return []
        index = 0
        while True:
            try:
                if list[index] < 0x10:
                    temp = list[index]
                    list.insert(index+1, temp|0x10)
                    list[index] = 0x02
                    index += 2
                else:
                    index += 1
            except:
                break
        return list[:]

    def __chksum__(self, list):
        chksum = 0
        for s in list:
            chksum = chksum ^ s
        return chksum

    def show(self):
        for s in self.message:
            print('0x%02x,')%s,
        print ''

    @staticmethod
    def display(lists):
        for s in lists:
            print('0x%02x,')%s,
        print ''

    @staticmethod
    def decode(list):
        for index, l in enumerate(list):
            if l == 0x02:
                del list[index]
                list[index] = list[index]&0x0f
        return list[:]

class mSerial(mThread):
    def __init__(self, com=SerialPort, baud=SerialBaud):
        super(mSerial,self).__init__()
        self.com = com
        self.baud = baud
        self.read_msg = []
        self.start_flag = False
        self.serial = None
        if not self.__open__():
            self.Print("Can't Open Serial")
            exit(1)

    def __open__(self):
        try:
            self.serial = serial.Serial(self.com, self.baud)
            self.serial.bytesize = 8
            self.serial.parity = 'N'
            self.serial.stopbits = 1
            self.serial.timeout = 0.05
            return True
        except Exception as e:
            self.Print(e)
            return False

    def send(self, data):
        try:
            print data
            n = self.serial.write(data)
            self.serial.flush()
            return n
        except serial.SerialException as e:
            self.Print(e)
            return -1

    def run(self):
        global mQueue
        while self.thread_state:
            c = self.serial.read(1)
            if c == '':
                continue
            if (c == 0x01) and (self.start_flag == False):
                self.read_msg.append(c)
                self.start_flag = True
            elif self.start_flag == True:
                self.read_msg.append(c)
            elif c == 0x03:
                self.read_msg.append(c)
                SLMsg = SerialMessage.decode(self.read_msg)
                SerialMessage.display(SLMsg)
                mQueue.put(SLMsg)

    def close(self):
        self.stop()
        self.serial.close()

    def Print(self, x):
        print "\033[31;1m" + "[ERR]", x, "\033[0m"

class SerialHandler(mThread):
    def __init__(self, thread_info=None, name=None):
        super(SerialHandler,self).__init__(thread_info,name)

    def run(self):
        global mQueue
        while self.thread_state:
            print 'waiting queue...'
            msg = mQueue.get()
            msg_type = msg[1]<<8 | msg[2]
            if msg_type == E_SL_MSG_GET_VERSION:
                self.thread_info.send(SerialMessage(type=0x8010).getdata())

if __name__ == '__main__':
    print 'python serial test'
    Serial = mSerial(com=SerialPort, baud=SerialBaud)
    Serial.start()
    SerialHandle = SerialHandler(thread_info = None, name = 'SerialHandle')
    SerialHandle.start()
    time.sleep(2)
    Serial.send(SerialMessage(type=0x0010).getdata())
    time.sleep(5)
    Serial.close()
    SerialHandle.stop()



