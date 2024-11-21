import cv2 as cv
import time
import math
import numpy as np
import serial
import board
import busio
from adafruit_ssd1306 import SSD1306_I2C
from PIL import Image, ImageDraw, ImageFont

# Initialize I2C
i2c = busio.I2C(board.SCL, board.SDA)

# Initialize the OLED display with the correct address and size (update if needed)
oled = SSD1306_I2C(128, 64, i2c, addr=0x3C)  # Replace 0x3C with your OLED's address if different

ser = serial.Serial("/dev/ttyACM0", 115200, timeout=1)

ser.setDTR(False)
time.sleep(1)
ser.flushInput()
ser.setDTR(True)
time.sleep(2)

or_tnc = 0
or_val = 0
bl_tnc = 0
bl_val = 0

test = cv.VideoCapture(1)

# Infinite loop to check if the camera is successfully opened
while not test.isOpened():
    print("Camera not opened. Retrying...")
    time.sleep(2)  # Wait for 2 seconds before retrying
    test.open(0)  # Try to reopen the camera

print("Camera opened successfully!")

test.set(3, 640)
test.set(4, 420)

LineColors = [[0, 63, 62, 16, 161, 226],
              [105, 103, 119, 114, 161, 160]]
LineValues = [[40, 43, 94],
              [110, 70, 45]]

myPoints = []  # [x, y, h, w, colorId]
width_for_constant_distance = 12  # minimum acceptable width

def display_message(message):
    # Clear the display
    oled.fill(0)
    oled.show()

    # Use a moderately larger font, for example, a 16-point font
    try:
        # Load a custom, smaller scaled font (adjust the font size to be appropriate)
        font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", 16)
    except IOError:
        font = ImageFont.load_default()  # Fall back to default if custom font isn't available

    # Create an image to draw on
    image = Image.new("1", (oled.width, oled.height))  # Create an empty screen
    draw = ImageDraw.Draw(image)

    # Draw text with the custom font
    draw.text((0, 0), message, font=font, fill=255)

    # Display the image on the OLED
    oled.image(image)
    oled.show()

def convert(k):
    res = 0
    if k > 240:
        res -= (k - 240)
    else:
        res += abs(k - 240)
    return res

def convert2(k):
    res = 0
    if k > 320:
        res -= (k - 320)
    else:
        res += abs(k - 320)
    return res

def findColor(frame):
    global or_tnc, or_val, bl_tnc, bl_val

    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    count = 0
    isln = 0
    hisab = []
    y = 82
    stre = []
    isbl = 0
    isor = 0
    or_tnc = 0
    or_val = 0
    bl_tnc = 0
    bl_val = 0
    for ln in LineColors:
        lower = np.array(ln[0:3])
        upper = np.array(ln[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        count += 1
        # cv.imshow(str(ln[0]), mask)
        if drawLine(mask, count) == 1:
            if count == 1:
                isbl = 1
            else:
                isor = 1
    stre.append(isln)
    if or_tnc > 0:
        or_val /= or_tnc
    if bl_tnc > 0:
        bl_val /= bl_tnc
    c = 0
    if isbl and isor:
        if or_val > bl_val:
            c = 2
        elif bl_val > or_val:
            c = 1
    rs = c
    if c == 0:
        display_message("nope")
    elif c == 1:
        display_message("left")
    elif c == 2:
        display_message("right")
    else:
        display_message("Unknown")
    num = chr(c)
    ser.write(num.encode('utf-8'))
    stre = []
    return

def drawLine(frame, cnt):
    global or_tnc, or_val, bl_tnc, bl_val
    edges = cv.Canny(frame, 50, 150, apertureSize=3)
    # cv.imshow('edges', edges)
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=100, maxLineGap=10)
    
    f = 0
    
    if lines is not None:
        for line in lines:
            f = 1
            x1, y1, x2, y2 = line[0]
            cv.line(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)

            # Calculate the slope (m)
            if x2 - x1 != 0:  # Prevent division by zero
                m = (y2 - y1) / (x2 - x1)
                b = y1 - m * x1
            if cnt == 1:
                bl_tnc += 1
                bl_val += b
            else:
                or_tnc += 1
                or_val += b

            # Draw the line on the frame
           
    # cv.imshow("aeh", frame)
    return f

while True:
    success, frame = test.read()
    frame_cc = frame.copy()
    findColor(frame)
    cv.imshow("Result", frame_cc)
    #time.sleep(350 / 1000)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

test.release()
cv.destroyAllWindows()
