#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2.cv as cv
import cv2

if __name__ == '__main__':
    capture=cv.CaptureFromCAM(0)
    dst = cv.CreateImage((int(cv.GetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_WIDTH)),
                        int(cv.GetCaptureProperty(capture, cv.CV_CAP_PROP_FRAME_HEIGHT))), 8, 1)
    while True:
        frame=cv.QueryFrame(capture)
        cv.CvtColor(frame, dst, cv.CV_BGR2GRAY)
        cv.Canny(dst, dst, 125, 350)
        cv.Threshold(dst, dst, 128, 255, cv.CV_THRESH_BINARY_INV)
        cv.ShowImage("The Video", frame)
        cv.ShowImage("The Dst", dst)
        c = cv.WaitKey(1)
        if c == 27: #Esc on Windows
            break