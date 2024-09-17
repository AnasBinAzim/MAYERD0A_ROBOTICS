import cv2 as cv
import time
import numpy as np
import serial
test = cv.VideoCapture(0)
test.set(3,480)
test.set(4,420)

ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)

ser.setDTR(False)
time.sleep(1)
ser.flushInput()
ser.setDTR(True)
time.sleep(2)

myColors = [[34,36,23,65,156,98],
            [118,137,130,129,252,186]]

LineColors = [[0,57,67,32,171,130]]
LineValues = [[40,43,94]]

myColorValues = [[19,78,50],
                 [186,49,65] ]        ## BGR

myPoints =  []  ## [x,y,h,w,colorId]
width_for_constant_distannce = 12
maximum_y_for_object = 200
x_boundary_for_red = 200
x_boundary_for_green = 400

def findColor(frame,myColors,myColorValues):
    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    count = 0
    re = 0
    gre = 0
    isln = 0
    hisab = []
    for color in myColors:
        lower = np.array(color[0:3])
        upper = np.array(color[3:6])
        mask = cv.inRange(frameHSV,lower,upper)
        list = getContours(mask)
        count += 1
        for obj in list:
            if obj[2] >= width_for_constant_distannce:
                x = obj[0]
                y = obj[1]
                w = -obj[2]
                h = obj[3]
                ls = [w,x,y,h,count]
                hisab.append(ls)
        cv.imshow(str(color[0]),mask)
    hisab.sort()
    if len(hisab) < 1:
        pass
    elif hisab[0][4]==1 and hisab[0][1] <= x_boundary_for_green:
        gre = 1
    elif hisab[0][4]==2 and hisab[0][1] >= x_boundary_for_red:
        re = 1
    count = 0
    for ln in LineColors:
        lower = np.array(ln[0:3])
        upper = np.array(ln[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        count += 1
        cv.imshow(str(ln[0]), mask)
        if drawLine(mask) == 1:
            if count == 1:
               isln = 1
    stre = ""
    if re == 1:
        stre = stre + 'R'
    elif gre == 1:
        stre = stre + 'G'
    else:
        stre = stre + 'N'
    if isln == 1:
        stre = stre + 'B'
    else:
        stre = stre + 'N'
    c = 0
    if stre == "NN":
        c = 0
    elif stre == "GN":
        c = 1
    elif stre == "RN":
        c = 2
    elif stre == "NB":
        c = 3
    elif stre == "GB":
        c = 4
    elif stre == "RB":
        c = 5
    num = c
    bb = f"{num}"
    ser.write(bb.encode('utf-8'))
   
    print(c)
    stre = ""
    return

    
def drawLine(frame):
    edges = cv.Canny(frame, 50, 150, apertureSize=3)
    cv.imshow('edges', edges)
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=100, maxLineGap=10)
    f = 0
    if lines is not None:
        for line in lines:
            f = 1
            x1, y1, x2, y2 = line[0]
            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)
    cv.imshow("aeh",frame_cc)
    return f


def getContours(frame):
    contours, meow = cv.findContours(frame,cv.RETR_EXTERNAL,cv.CHAIN_APPROX_NONE)
    x,y,w,h = 0,0,0,0
    me = 0
    list = []
    for cnt in contours:
        area = cv.contourArea(cnt)
        if area>100:
            cv.drawContours(frame_cc, cnt, -1, (255, 0, 0), 3)
            peri = cv.arcLength(cnt,True)
            approx = cv.approxPolyDP(cnt,0.02*peri,True)
            x, y, w, h = cv.boundingRect(approx)
            x = x + w/2
            y = y + h/2
            rect = [x, y, w, h]
            list.append(rect)
    return list

while True:
    success, frame = test.read()
    frame_cc = frame.copy()
    findColor(frame, myColors,myColorValues)
    cv.imshow("Result", frame_cc)
    
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
test.release()
cv.destroyAllWindows()
