
import cv2 as cv
import time
import math
import numpy as np
import serial

test = cv.VideoCapture(0)
test.set(3, 640)
test.set(4, 420)

ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)

ser.setDTR(False)
time.sleep(1)
ser.flushInput()
ser.setDTR(True)
time.sleep(2)

myColors = [[179,255,255,0,0,0],
            [34, 65 ,23, 80, 205, 62],
            [114,192,79,125,232,118]]

LineColors = [[0,58,72,21,175,123],
                [107,110,130,119,175,141]]
LineValues = [[40, 43, 94],
                [110,70,45]]

myColorValues = [[19, 78, 50],
                 [186, 49, 65]]  # BGR

myPoints = []  # [x, y, h, w, colorId]
width_for_constant_distance = 12  # minimum acceptable width
width_for_black_distance = 64
maximum_y_for_object = 82
x_boundary_for_red = 40
x_boundary_for_green = 600

is_obj = 0
obj_w = 0
obj_x = 0

# for turn
object_maximum_width = 62
object_minimum_width = 25
# red tuning
x_boundary_for_red = 40
red_left = 150
red_right = 640

# green tuning
x_boundary_for_green = 600
green_left = 0
green_right = 490

obj_dist_ratio = object_maximum_width - object_minimum_width
obj_depth = green_right - green_left
turning_radius = 0


def findColor(frame, myColors, myColorValues):
    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    count = 0
    re = 0
    gre = 0
    isln = 0
    hisab = []
    y = 82
    stre = []
    is_obj = 0
    obj_w = 0
    obj_x = 0

    cv.line(frame_cc, (160, y), (480, y), (186, 46, 95), 3)
    cv.line(frame_cc, (0, 142), (160, y), (186, 46, 95), 3)
    cv.line(frame_cc, (480, y), (640, 142), (186, 46, 95), 3)

    for color in myColors:
        lower = np.array(color[0:3])
        upper = np.array(color[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        list = getContours(mask)
        count += 1
        for obj in list:
            if count == 1 and obj[2] >= width_for_black_distance:
                print("I am black")
                x = obj[0]
                y = int(obj[1])
                w = -obj[2]
                h = obj[3]
                y = 82

            elif count != 1 and obj[2] >= width_for_constant_distance:
                x = obj[0]
                y = obj[1]
                w = obj[2]
                h = obj[3]
                if w > h:
                    temp = w
                    w = h
                    h = temp
                w = -w
                if y >= maximum_y_for_object:
                    ls = [w, x, y, h, count]
                    hisab.append(ls)
        # cv.imshow(str(color[0]), mask)

    hisab.sort()

    if len(hisab) < 1:
        pass
    elif hisab[0][4] == 2 and hisab[0][1] <= x_boundary_for_green:
        x = int(hisab[0][1])
        y = int(hisab[0][2])
        w = int(hisab[0][0])
        h = int(hisab[0][3])
        cv.circle(frame_cc, (x, y), 10, (0, 255, 0), -1)

        gre = 1
        is_obj = 1
        obj_w = -w
        obj_x = x
    elif hisab[0][4] == 3 and hisab[0][1] >= x_boundary_for_red:
        re = 1
        x = int(hisab[0][1])
        y = int(hisab[0][2])
        w = int(hisab[0][0])
        h = int(hisab[0][3])
        cv.circle(frame_cc, (x, y), 10, (0, 0, 255), -1)
        is_obj = 1
        obj_w = -w
        obj_x = x
        # print(x)
        # print(w)
    turning_radius = 100
    if is_obj == 0:
        stre.append(100)
    else:
        if re == 1:
            obj_x = obj_x - red_left
            if obj_x < 0:
                obj_x = 0
            
            obj_x /= obj_depth
            obj_x = math.sqrt(obj_x)
            if(obj_x > 1):
                obj_x = 1
            obj_w = obj_w - object_minimum_width
            if obj_w < 0:
                obj_w = 0            
            obj_w = obj_w / obj_dist_ratio
            obj_w = math.sqrt(obj_w)
            if(obj_w > 1):
                obj_w = 1
            turning_radius = obj_w * obj_x
            #turning_radius = math.sqrt(turning_radius)
            if(turning_radius > 1):
                turning_radius = 1
            turning_radius *= 70
            #if turning_radius  == 0:
             #   turning_radius = 1 
            turning_radius = 100 - turning_radius
        elif gre == 1:
            obj_x = green_right - obj_x
            if obj_x < 0:
                obj_x = 0            
            obj_x /= obj_depth
            obj_x = math.sqrt(obj_x)
            if(obj_x > 1):
                
                obj_x = 1
            obj_w = obj_w - object_minimum_width
            if obj_w < 0:
                obj_w = 0            
            obj_w = obj_w / obj_dist_ratio
            obj_w = math.sqrt(obj_w)
            if(obj_w > 1):
                obj_w = 1
            #print(obj_w)
            #print(obj_x)
            turning_radius = obj_w * obj_x
            #turning_radius = math.sqrt(turning_radius)
            if(turning_radius > 1):
                turning_radius = 1
            #print(turning_radius)
            turning_radius *= 60
           # if turning_radius  == 0:
            #    turning_radius = 1
            #print(turning_radius)
            turning_radius = 100 + turning_radius
        turning_radius = int(turning_radius)
        stre.append(turning_radius)
    print(turning_radius)
    count = 0
    isbl = 0
    isor = 0
    for ln in LineColors:
        lower = np.array(ln[0:3])
        upper = np.array(ln[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        count += 1
        # cv.imshow(str(ln[0]), mask)
        if drawLine(mask) == 1:
            if count == 1:
                isbl = 1
            else :
                isor = 1
    stre.append(isln)
    c = turning_radius - 40
    c = c/3
    c = int(c)
    if(isbl):
        c += 40
    elif isor:
        c += 80
    print(c)
    num = chr(c)
   # if(ser.in_waiting > 0):
        #rd = ser.read().decode()
        #print("from arduino")
        #print("a")
       # if(rd == 'a'):
    ser.write(num.encode('utf-8'))
    
    stre = []
    return


def drawLine(frame):
    edges = cv.Canny(frame, 50, 150, apertureSize=3)
    # cv.imshow('edges', edges)
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=100, maxLineGap=10)
    f = 0
    if lines is not None:
        for line in lines:
            f = 1
            x1, y1, x2, y2 = line[0]
            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)
    # cv.imshow("aeh", frame_cc)
    return f


def getContours(frame):
    contours, meow = cv.findContours(frame, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_NONE)
    x, y, w, h = 0, 0, 0, 0
    list = []
    for cnt in contours:
        area = cv.contourArea(cnt)
        if area > 100:
            cv.drawContours(frame_cc, cnt, -1, (255, 0, 0), 3)
            peri = cv.arcLength(cnt, True)
            approx = cv.approxPolyDP(cnt, 0.02 * peri, True)
            x, y, w, h = cv.boundingRect(approx)
            x = x + w / 2
            y = y + h / 2
            rect = [x, y, w, h]
            list.append(rect)
    return list


while True:
    success, frame = test.read()
    frame_cc = frame.copy()
    findColor(frame, myColors, myColorValues)
    cv.imshow("Result", frame_cc)
    #time.sleep(350 / 1000)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

test.release()
cv.destroyAllWindows()
