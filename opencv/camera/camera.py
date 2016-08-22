#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2
import numpy as np

if __name__ == '__main__':
    capture = cv2.VideoCapture(0)

    #fourcc = cv2.VideoWriter_fourcc(*'XVID') #this version is not support this method
    fourcc = cv2.cv.CV_FOURCC(*'XVID')
    out = cv2.VideoWriter('output.avi', fourcc, 30.0, (640,480))
    while capture.isOpened():
        ret, frame = capture.read()
        if ret == True:
            cv2.imshow("Camera", frame)
            print frame.cows
            #frame_w = cv2.flip(frame, 0) #overturn picture
            #out.write(frame)
        if cv2.waitKey(1)&0xff == ord('q'):
            break
    capture.release()
    out.release()
    cv2.destroyAllWindows()