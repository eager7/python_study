#!/usr/bin/env python
# -*- coding: utf-8 -*-

#from serial import serial
import serial

SerialPort = '/dev/ttyUSB0'
SerialBaud = 115200

__metaclass__ = type
class mSerial():
    def __init__(self, com=SerialPort, baud=SerialBaud):
        self.com = com
        self.baud = baud

    def Open(self):
        try:
            self.ser = serial.Serial(self.com, self.baud)
            return True
        except Exception as e:
            self.Print(e)
            return False

    def Write(self, data):
        try:
            n = self.ser.write(data)
            return n
        except serial.SerialException as e:
            return -1

    def Read(self):
        return self.ser.read_all()

    def Close(self):
        self.ser.close()

    def Print(self, x):
        print "\033[31;1m" + "[ERR]", x, "\033[0m"

class SerialMessage():
    def __init__(self, type=0, data=None):
        self.type = []
        length = len(data)
        message = [0x01,(type<<8)&0xff,type&0xff,(length<<8)&0xff,length&0xff,0x00]
        message.extend(data)
        message.append(0x03)
        self.message = message[:]
        self.Chksum()
        self.Format()

    def Format(self, msg):
        for index, s in enumerate(self.message):
            if s < 0x10:
                self.message.insert(index,[0x02, s|0x10])

    def Chksum(self):
        chksum = 0
        for s in self.message:
            chksum = chksum ^ s
        self.message[5] = chksum

if __name__ == '__main__':
    print 'python serial test'
    #Serial = serial.Serial(port=SerialPort, baudrate=SerialBaud)
    #print Serial.isOpen()
    #print Serial.portstr
    #print Serial.write('abc\n')
    ##print Serial.inWaiting()
    #print readline(Serial)
    #Serial.close()

    msg = SerialMessage(type=0x01,data=[0x12,0x15])
    print msg.message
    for m in msg.message:
        print m