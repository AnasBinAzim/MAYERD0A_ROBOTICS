import cv2 as cv
import numpy as np
from numpy.f2py.auxfuncs import istrue
from numpy.ma.core import resize


frame = cv.imread('1.jpg')

frameHsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
cv.imshow("rakib",frameHsv)
cv.waitKey((0))

# temp = cv.VideoCapture('D:\mayre_doa_robotics\Opncv\Videoes\VID_20240913_095623.mp4')
#
# def resize_frame(framee,scale = 0.25):
#     # he = int(framee.shape[0] * scale)
#     # wi = int(framee.shape[1] * scale)
#     fr = cv.resize(framee,(240,320))
#     return fr
#
#
#
# while True:
#     isTrue,frame = temp.read()
#     # frame = resize_frame(framee,0.5)
#     frameHsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
#     cv.imshow("Rakib",frameHsv)
#     if cv.waitKey(1) & 0xFF == ord('q'):
#         break
#
# temp.release()
# cv.destroyAllWindows()