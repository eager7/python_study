#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2
import cv2.cv as cv


if __name__ == '__main__':
    cv.NamedWindow("camera",1)
    capture = cv.CaptureFromCAM(0)

    while True:
        img = cv.QueryFrame(capture)
        cv.ShowImage("camera",img)

        if cv.WaitKey(100) == 27:
            cv.DestroyWindow("camera")
            print 'close'
            break