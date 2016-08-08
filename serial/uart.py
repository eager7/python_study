#!/usr/bin/env python
# -*- coding: utf-8 -*-

from mThread import mThread
import serial,time,Queue
#---------------------------------------------------------------#
#                          Serial Setting                       #
#---------------------------------------------------------------#
SerialPort = '/dev/ttyUSB0'
SerialBaud = 115200
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

if __name__ == '__main__':
    print 'python serial test'
    Serial = serial.Serial(port=SerialPort,baudrate=115200,bytesize=8,parity='N',stopbits=1,timeout=0.5,rtscts=True,dsrdtr=True)
    print 'open success..'
    while True:
        s = raw_input('')
        if s == 'q':
            Serial.close()
            break
        Serial.write(s)
        print Serial.read(1)


