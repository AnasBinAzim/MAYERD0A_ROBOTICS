import cv2 as cv
import time
import math
import numpy as np
import serial

# ser = serial.Serial("/dev/ttyACM0", 115200, timeout=1)
#
# ser.setDTR(False)
# time.sleep(1)
# ser.flushInput()
# ser.setDTR(True)
# time.sleep(2)
bl_min = 1000000
bl_max = -1000000
or_min = 1000000
or_max = -1000000

test = cv.VideoCapture(1)

# Infinite loop to check if the camera is successfully opened
while not test.isOpened():
    print("Camera not opened. Retrying...")
    time.sleep(2)  # Wait for 2 seconds before retrying
    test.open(0)  # Try to reopen the camera

print("Camera opened successfully!")

test.set(3, 640)
test.set(4, 420)

LineColors = [[0,63,62,16,161,226],
                [105,103,119,114,161,160]]
LineValues = [[40, 43, 94],
                [110,70,45]]

myPoints = []  # [x, y, h, w, colorId]
width_for_constant_distance = 12  # minimum acceptable width

def findColor(frame):
    global bl_min, bl_max, or_min, or_max

    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    count = 0
    re = 0
    gre = 0
    isln = 0
    hisab = []
    y = 82
    stre = []
    count = 0
    isbl = 0
    isor = 0
    bl_min = 1000000
    bl_max = -1000000
    or_min = 1000000
    or_max = -1000000
    for ln in LineColors:
        lower = np.array(ln[0:3])
        upper = np.array(ln[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        count += 1
        # cv.imshow(str(ln[0]), mask)
        if drawLine(mask,count) == 1:
            if count == 1:
                isbl = 1
            else :
                isor = 1
    stre.append(isln)
    c = 0
    if isbl and isor:
        if or_min > bl_max:
            c = 2
        elif bl_min > or_max:
            c = 1
    num = chr(c)
    print(c)
    print("is or " + chr(isor))
    print("is bl " + chr(isbl))

    # print("or Max")
    # print(or_min)
    # print(or_max)
    # print(bl_min)
    # print(bl_max)
    print(c)
    #ser.write(num.encode('utf-8'))
      # Indentation fixed here
    stre = []
    return


def drawLine(frame, cnt):
    global bl_min, bl_max, or_min, or_max  # Declare the global variables
    edges = cv.Canny(frame, 50, 150, apertureSize=3)
    # cv.imshow('edges', edges)
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=100, maxLineGap=10)
    f = 0
    print(cnt)
    if lines is not None:
        for line in lines:
            f = 1
            x1, y1, x2, y2 = line[0]
            if(cnt == 1):
                ydis = (y1 - y2)
                xdis = abs(x1 - x2)
                dhal = ydis / xdis
                if(bl_min > dhal):
                    bl_min = dhal
                if(dhal > bl_max):
                    bl_max = dhal

            else:
                ydis = (y1 - y2)
                xdis = abs(x1 - x2)
                dhal = ydis / xdis
                if (or_min > dhal):
                    or_min = dhal
                if (dhal > or_max):
                    or_max = dhal

            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)
    # cv.imshow("aeh", frame_cc)
    return f



while True:
    success, frame = test.read()
    frame_cc = frame.copy()
    findColor(frame)
    cv.imshow("Result", frame_cc)
    time.sleep(350 / 1000)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

test.release()
cv.destroyAllWindows()
