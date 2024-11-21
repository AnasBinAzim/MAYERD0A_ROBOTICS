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


from PIL import ImageDraw

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
    draw.arc([x1, y1, x1 + 2 * radius, y1 + 2 * radius], start=180, end=270, fill=outline, width=width)  # top-left corner
    draw.arc([x2 - 2 * radius, y1, x2, y1 + 2 * radius], start=270, end=360, fill=outline, width=width)  # top-right corner
    draw.arc([x1, y2 - 2 * radius, x1 + 2 * radius, y2], start=90, end=180, fill=outline, width=width)  # bottom-left corner
    draw.arc([x2 - 2 * radius, y2 - 2 * radius, x2, y2], start=0, end=90, fill=outline, width=width)  # bottom-right corner

    # Draw the 4 sides of the rectangle
    draw.line([x1 + radius, y1, x2 - radius, y1], fill=outline, width=width)  # top side
    draw.line([x1 + radius, y2, x2 - radius, y2], fill=outline, width=width)  # bottom side
    draw.line([x1, y1 + radius, x1, y2 - radius], fill=outline, width=width)  # left side
    draw.line([x2, y1 + radius, x2, y2 - radius], fill=outline, width=width)  # right side

# Example usage in your `display_message` function:
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
    draw_rounded_rectangle(draw, border_margin, border_margin, oled.width - border_margin, oled.height - border_margin, 10, outline=255, width=2)

    # Draw the title line
    draw_centered_text("Mayerdoa_Robotics", 6)  # Title line at the top

    # Draw the three lines with appropriate vertical spacing
    draw_centered_text(line1, font_size + 8)  # First line
    draw_centered_text(line2, 2 * font_size + 10)  # Second line (depends on variable `d`)
    draw_centered_text(line3, 3 * font_size + 12)  # Third line (depends on variable `e`)

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

        if drawLine(mask, count) == 1:  # Check if line is detected
            if count == 1:
                isbl = 1  # Blue line detected
            else:
                isor = 1  # Orange line detected

    # Process the line counts and averages
    if or_tnc > 0:
        or_val /= or_tnc
    if bl_tnc > 0:
        bl_val /= bl_tnc

    # Determine direction based on line color values
    c = 0
    if isbl and isor:
        if or_val > bl_val:
            c = 2  # Orange line is more dominant
        elif bl_val > or_val:
            c = 1  # Blue line is more dominant

    # Display results based on the detected direction
    if c == 0:
        display_message("nope", "bal", "bal")  # No line detected
    elif c == 1:
        display_message("left", "bal", "bal")  # Blue line detected, turn left
    elif c == 2:
        display_message("right", "bal", "bal")  # Orange line detected, turn right
    else:
        display_message("Unknown", "bal", "bal")  # Unknown condition

    # Send the result via serial communication
    num = chr(c)
    ser.write(num.encode('utf-8'))

    # Reset the processing variables for the next frame
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
            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)

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
    # time.sleep(350 / 1000)
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

test.release()
cv.destroyAllWindows()
