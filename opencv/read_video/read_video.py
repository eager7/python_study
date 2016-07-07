#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2
import numpy as np

if __name__ == '__main__':
    capture = cv2.VideoCapture(r'/home/firefly/pct/python_study/opencv/camera/output.avi')
    print capture.isOpened()
    while capture.isOpened():
        ret, frame = capture.read()
        if ret == True:
            cv2.imshow("Camera", frame)
        else:
            break
        if cv2.waitKey(1)&0xff == ord('q'):
            break
    capture.release()
    cv2.destroyAllWindows()