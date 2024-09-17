import cv2 as cv
import numpy as np
from numpy.f2py.auxfuncs import istrue
from numpy.ma.core import resize

temp = cv.VideoCapture(0)

frameWidth = 1080
frameHeight = 320
temp.set(3, frameWidth)
temp.set(4, frameHeight)
temp.set(10,30)

def resize_frame(framee,scale = 0.25):
    # he = int(framee.shape[0] * scale)
    # wi = int(framee.shape[1] * scale)
    fr = cv.resize(framee,(320,240))
    return fr

def aeh(a):
    pass

cv.namedWindow("HSV")
cv.resizeWindow("HSV", 640, 240)
cv.createTrackbar("H Min", "HSV", 0, 179, aeh)
cv.createTrackbar("H Max", "HSV", 179, 179, aeh)
cv.createTrackbar("S Min", "HSV", 0, 255, aeh)
cv.createTrackbar("S Max", "HSV", 255, 255, aeh)
cv.createTrackbar("V Min", "HSV", 0, 255, aeh)
cv.createTrackbar("V Max", "HSV", 255, 255, aeh)

while True:
    isTrue,framee = temp.read()
    frame = resize_frame(framee,0.5)
    frameHsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    cv.imshow("Rakib",frameHsv)
    h_min = cv.getTrackbarPos("H Min", "HSV")
    h_max = cv.getTrackbarPos("H Max", "HSV")
    s_min = cv.getTrackbarPos("S Min", "HSV")
    s_max = cv.getTrackbarPos("S Max", "HSV")
    v_min = cv.getTrackbarPos("V Min", "HSV")
    v_max = cv.getTrackbarPos("V Max", "HSV")


    lower = np.array([h_min, s_min, v_min])
    upper = np.array([h_max, s_max, v_max])
    mask = cv.inRange(frameHsv, lower, upper)
    result = cv.bitwise_and(frame, frame, mask=mask)

    mask = cv.cvtColor(mask, cv.COLOR_GRAY2BGR)
    cv.imshow("end",mask)
    hStack = np.hstack([frame, mask, result])
    cv.imshow('Horizontal Stacking', hStack)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

temp.release()
cv.destroyAllWindows()