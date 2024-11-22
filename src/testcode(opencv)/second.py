import cv2 as cv
import time
import math
import numpy as np
import serial

from aehhhh import neon_color

# import board
# import busio
# from adafruit_ssd1306 import SSD1306_I2C
#from PIL import Image, ImageDraw, ImageFont

# Initialize I2C
#i2c = busio.I2C(board.SCL, board.SDA)

# Initialize the OLED display with the correct address and size (update if needed)
#oled = SSD1306_I2C(128, 64, i2c, addr=0x3C)  # Replace 0x3C with your OLED's address if different

#ser = serial.Serial("/dev/ttyACM0", 115200, timeout=1)

#ser.setDTR(False)
#time.sleep(1)
#ser.flushInput()
#ser.setDTR(True)
#time.sleep(2)

test = cv.VideoCapture(1)

# Infinite loop to check if the camera is successfully opened
while not test.isOpened():
    print("Camera not opened. Retrying...")
    time.sleep(2)  # Wait for 2 seconds before retrying
    test.open(0)  # Try to reopen the camera

print("Camera opened successfully!")

test.set(3, 640)
test.set(4, 420)

LineColors = [[0, 35, 68, 84, 168, 226],
              [98, 40, 93, 122, 112, 159]]
LineValues = [[40, 43, 94],
              [110, 70, 45]]
myColors = [[179, 255, 255, 0, 0, 0],
            [34, 65, 23, 80, 205, 62],
            [110, 160, 98, 129, 214, 136]]
myColorValues = [[19, 78, 50],
                 [186, 49, 65]]  # BGR

neon_color = (57, 255, 20)
frame_cc = np.zeros((480, 640, 3), dtype=np.uint8)  # A 300x640 blank frame
frame_cc[:] = neon_color

# Neon green background in BGR format

or_tnc = 0
or_val = 0
bl_tnc = 0
bl_val = 0

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

def draw_rounded_rectangle(draw, x1, y1, x2, y2, radius, outline, width):
    """
    Draw a rounded rectangle.
    draw: ImageDraw object
    x1, y1, x2, y2: Coordinates of the bounding box (top-left and bottom-right)
    radius: Radius of the rounded corners
    outline: Color of the outline
    width: Line width
    """
    # Draw the 4 corners as circles (arcs) and the 4 sides as lines
    draw.arc([x1, y1, x1 + 2 * radius, y1 + 2 * radius], start=180, end=270, fill=outline,
             width=width)  # top-left corner
    draw.arc([x2 - 2 * radius, y1, x2, y1 + 2 * radius], start=270, end=360, fill=outline,
             width=width)  # top-right corner
    draw.arc([x1, y2 - 2 * radius, x1 + 2 * radius, y2], start=90, end=180, fill=outline,
             width=width)  # bottom-left corner
    draw.arc([x2 - 2 * radius, y2 - 2 * radius, x2, y2], start=0, end=90, fill=outline,
             width=width)  # bottom-right corner

    # Draw the 4 sides of the rectangle
    draw.line([x1 + radius, y1, x2 - radius, y1], fill=outline, width=width)  # top side
    draw.line([x1 + radius, y2, x2 - radius, y2], fill=outline, width=width)  # bottom side
    draw.line([x1, y1 + radius, x1, y2 - radius], fill=outline, width=width)  # left side
    draw.line([x2, y1 + radius, x2, y2 - radius], fill=outline, width=width)  # right side


# Example usage in your display_message function:
def display_message(line1, line2, line3, font_size=10):
    try:
        font = ImageFont.truetype("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf", font_size)
    except IOError:
        font = ImageFont.load_default()

    # Create an image to draw on
    image = Image.new("1", (oled.width, oled.height))
    draw = ImageDraw.Draw(image)

    # Helper function to draw a centered text
    def draw_centered_text(text, y_offset):
        text_width, text_height = draw.textsize(text, font=font)
        x = (oled.width - text_width) // 2  # Center the text
        draw.text((x, y_offset), text, font=font, fill=255)

    # Clear the screen by filling it with black
    draw.rectangle((0, 0, oled.width, oled.height), outline=0, fill=0)

    # Draw a border with rounded corners around the screen
    border_margin = 2
    draw_rounded_rectangle(draw, border_margin, border_margin, oled.width - border_margin, oled.height - border_margin,
                           10, outline=255, width=2)

    # Draw the title line
    draw_centered_text("Mayerdoa_Robotics", 6)  # Title line at the top

    # Draw the three lines with appropriate vertical spacing
    draw_centered_text(line1, font_size + 8)  # First line
    draw_centered_text(line2, 2 * font_size + 10)  # Second line (depends on variable d)
    draw_centered_text(line3, 3 * font_size + 12)  # Third line (depends on variable e)

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
    global frame_cc,neon_color
    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)
    count = 0
    re = 0
    gre = 0
    hisab = []
    y = 96
    is_obj = 0
    obj_w = 0
    obj_x = 0

    cv.rectangle(frame_cc, (0, y + 1), (640, 480), (255, 255, 255), -1)

    # Define points of the first triangle (coordinates in (x, y))
    points_1 = np.array([[640, y], [480, y], [640, 142]])

    # Reshape the points in the shape required by fillPoly (number of points, 1, 2)
    points_1 = points_1.reshape((-1, 1, 2))

    # Draw the first filled polygon (triangle) with a bright neon color (cyan)
    neon_color_1 = (0, 255, 255)  # Bright yellowish-cyan color in BGR format
    cv.fillPoly(frame_cc, [points_1], color=neon_color)

    # Define points of the second triangle (coordinates in (x, y))
    points_2 = np.array([[0, y], [160, y], [0, 142]])

    # Reshape the points in the shape required by fillPoly (number of points, 1, 2)
    points_2 = points_2.reshape((-1, 1, 2))

    # Draw the second filled polygon (triangle) with another bright neon color (e.g., magenta)  # Bright pink/magenta color in BGR format
    cv.fillPoly(frame_cc, [points_2], color=neon_color)

    # Display the image with the filled neon triangle

    line_color = (25, 25, 25)  # Updated line color
    line_thickness = 15  # Five times thicker than before

    cv.line(frame_cc, (160, y), (480, y), line_color, line_thickness)  # Horizontal line
    cv.line(frame_cc, (0, 142), (160, y), line_color, line_thickness)  # Diagonal line (left)
    cv.line(frame_cc, (480, y), (640, 142), line_color, line_thickness)  # Diagonal line (right)

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
        pass
    else:
        if re == 1:
            obj_x = obj_x - red_left
            if obj_x < 0:
                obj_x = 0

            obj_x /= obj_depth
            obj_x = math.sqrt(obj_x)
            if (obj_x > 1):
                obj_x = 1
            obj_w = obj_w - object_minimum_width
            if obj_w < 0:
                obj_w = 0
            obj_w = obj_w / obj_dist_ratio
            obj_w = math.sqrt(obj_w)
            if (obj_w > 1):
                obj_w = 1
            turning_radius = obj_w * obj_x
            # turning_radius = math.sqrt(turning_radius)
            if (turning_radius > 1):
                turning_radius = 1
            turning_radius *= 70
            # if turning_radius  == 0:
            #   turning_radius = 1
            turning_radius = 100 - turning_radius
        elif gre == 1:
            obj_x = green_right - obj_x
            if obj_x < 0:
                obj_x = 0
            obj_x /= obj_depth
            obj_x = math.sqrt(obj_x)
            if (obj_x > 1):
                obj_x = 1
            obj_w = obj_w - object_minimum_width
            if obj_w < 0:
                obj_w = 0
            obj_w = obj_w / obj_dist_ratio
            obj_w = math.sqrt(obj_w)
            if (obj_w > 1):
                obj_w = 1
            # print(obj_w)
            # print(obj_x)
            turning_radius = obj_w * obj_x
            # turning_radius = math.sqrt(turning_radius)
            if (turning_radius > 1):
                turning_radius = 1
            # print(turning_radius)
            turning_radius *= 60
            # if turning_radius  == 0:
            #    turning_radius = 1
            # print(turning_radius)
            turning_radius = 100 + turning_radius
        turning_radius = int(turning_radius)
    print(turning_radius)
    count = 0
    isbl = 0
    isor = 0
    or_tnc = 1000000
    or_val = -1000000
    bl_tnc = 1000000
    bl_val = -1000000
    for ln in LineColors:
        lower = np.array(ln[0:3])
        upper = np.array(ln[3:6])
        mask = cv.inRange(frameHSV, lower, upper)
        count += 1
        if drawLine(mask, count) == 1:  # Check if line is detected
            if count == 1:
                isbl = 1  # Blue line detected
            else:
                isor = 1  # Orange line detected

    c = 0
    ln1 = "1"
    ln2 = "2"
    ln3 = "3"
    ln1 = "nope"
    ln3 = "Nope"
    if isbl and isor:
        if or_tnc < bl_val:
            c = 1  # Blue line is more dominant
            ln1 = "left"
        elif bl_tnc < or_val:
            c = 2  # Orange line is more dominant
            ln1 = "right"
        else:
            ln1 = "ERROR"
    elif isbl:
        c = 1
        ln3 = "left"
    elif isor:
        c = 2
        ln3 = "right"

    if isor or isbl:
        ln2 = "Detected"
    else:
        ln2 = "No Line"
    #display_message(ln1, ln2, ln3)
    c = turning_radius - 40
    c = c / 3
    c = int(c)
    if (c == 1):
        c += 40
    elif (c == 2):
        c += 80
    print(c)
    num = chr(c)
    #ser.write(num.encode('utf-8'))
    return


def drawLine(frame, cnt):
    global or_tnc, or_val, bl_tnc, bl_val
    edges = cv.Canny(frame, 50, 150, apertureSize=3)
    # cv.imshow('edges', edges)
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=70, maxLineGap=10)

    f = 0

    if lines is not None:
        for line in lines:
            f = 1
            x1, y1, x2, y2 = line[0]
            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)

            # Calculate the slope (m)
            if x2 - x1 != 0:  # Prevent division by zero
                m = (y2 - y1) / (x2 - x1)
                b = y1 - m * x1
                b = int(b)
                if cnt == 1:
                    bl_tnc = min(bl_tnc, b)
                    bl_val = max(bl_val, b)
                else:
                    or_tnc = min(or_tnc, b)
                    or_val = max(or_val, b)

            # Draw the line on the frame

    # cv.imshow("aeh", frame)
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
    frame = cv.GaussianBlur(frame, (5, 5), 0)
    frame_cc = frame.copy()
    frame_cc = np.zeros((480, 640, 3), dtype=np.uint8)  # A 300x640 blank frame
    frame_cc[:] = (57, 255, 20)  # Neon green background in BGR format
    findColor(frame)
    cv.imshow("Result", frame_cc)
    # time.sleep(350 / 1000)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

oled.fill(0)
oled.show()
test.release()
cv.destroyAllWindows()