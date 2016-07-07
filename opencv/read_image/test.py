#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2
import numpy as np

if __name__ == '__main__':
    print "camera display"
    cv2.namedWindow("Image window")
    img = cv2.imread("test.jpg")
    print img.shape #437, 508, 3
    cv2.imshow("Image window", img)
    cv2.waitKey(3000)
    img2 = cv2.cvtColor(img,cv2.COLOR_BGRA2GRAY)
    cv2.imshow("Image window", img2)
    print img2.shape #437, 508
    cv2.waitKey(3000)
    cv2.destroyAllWindows()
