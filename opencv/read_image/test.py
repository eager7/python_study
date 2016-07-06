#!/usr/bin/env python
# -*- coding: utf-8 -*-

import cv2
from sensor_msgs.msg import Image
from cv_bridge import CvBridge, CvBridgeError


if __name__ == '__main__':
    print "camera display"
    cv2.namedWindow("Image window")
    img = cv2.imread("test.jpg")
    cv2.imshow("Image window", img)
    cv2.waitKey(3000)
    cv2.destroyAllWindows()
