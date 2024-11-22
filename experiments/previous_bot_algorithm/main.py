
import cv2 as cv  # Import OpenCV library
import time  # Import time library for delays
import numpy as np  # Import NumPy for numerical operations
import serial  # Import PySerial for serial communication

# Initialize video capture from the first camera (0)
test = cv.VideoCapture(0)
# Set the width and height of the video capture
test.set(3, 480)  # Set width to 480
test.set(4, 420)  # Set height to 420

# Initialize serial communication on the specified port at 9600 baud rate
ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)

# Reset the DTR line to establish a clean connection
ser.setDTR(False)
time.sleep(1)  # Wait for 1 second
ser.flushInput()  # Clear input buffer
ser.setDTR(True)  # Set DTR high
time.sleep(2)  # Wait for 2 seconds to stabilize the connection

# Define color ranges in HSV format for detection
myColors = [[34, 36, 23, 65, 156, 98],
            [118, 137, 130, 129, 252, 186]]

# Define line colors and their corresponding detection ranges
LineColors = [[0, 57, 67, 32, 171, 130]]
LineValues = [[40, 43, 94]]

# Define the color values in BGR format
myColorValues = [[19, 78, 50],
                 [186, 49, 65]]  # BGR

myPoints = []  # Initialize a list to store detected points
width_for_constant_distance = 12  # Width threshold for detected objects
maximum_y_for_object = 200  # Maximum Y-coordinate for object detection
x_boundary_for_red = 200  # X boundary for red detection
x_boundary_for_green = 400  # X boundary for green detection

# Function to find colors in the frame
def findColor(frame, myColors, myColorValues):
    frameHSV = cv.cvtColor(frame, cv.COLOR_RGB2HSV)  # Convert the frame to HSV color space
    count = 0
    re = 0  # Red detection flag
    gre = 0  # Green detection flag
    isln = 0  # Line detection flag
    hisab = []  # List to store detected objects

    # Loop through each color range
    for color in myColors:
        lower = np.array(color[0:3])  # Define lower HSV bound
        upper = np.array(color[3:6])  # Define upper HSV bound
        mask = cv.inRange(frameHSV, lower, upper)  # Create a mask for the color
        list = getContours(mask)  # Get contours of detected areas
        count += 1
        for obj in list:
            if obj[2] >= width_for_constant_distance:  # Check if the width is above the threshold
                x = obj[0]
                y = obj[1]
                w = -obj[2]  # Width (negated for some reason)
                h = obj[3]
                ls = [w, x, y, h, count]  # Store details of the object
                hisab.append(ls)  # Add object details to the list
        cv.imshow(str(color[0]), mask)  # Show the mask for the current color

    hisab.sort()  # Sort the detected objects
    if len(hisab) < 1:
        pass  # No objects detected
    elif hisab[0][4] == 1 and hisab[0][1] <= x_boundary_for_green:
        gre = 1  # Detected green object
    elif hisab[0][4] == 2 and hisab[0][1] >= x_boundary_for_red:
        re = 1  # Detected red object

    count = 0
    for ln in LineColors:
        lower = np.array(ln[0:3])  # Define lower line color bound
        upper = np.array(ln[3:6])  # Define upper line color bound
        mask = cv.inRange(frameHSV, lower, upper)  # Create a mask for line color
        count += 1
        cv.imshow(str(ln[0]), mask)  # Show the mask for line color
        if drawLine(mask) == 1:  # Check if a line is detected
            if count == 1:
                isln = 1  # Line detected

    # Construct output string based on detections
    stre = ""
    if re == 1:
        stre += 'R'  # Red detected
    elif gre == 1:
        stre += 'G'  # Green detected
    else:
        stre += 'N'  # No color detected

    if isln == 1:
        stre += 'B'  # Line detected
    else:
        stre += 'N'  # No line detected

    # Map output string to a number for sending via serial
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

    # Send the corresponding number over serial
    bb = f"{c}"  # Convert number to string
    ser.write(bb.encode('utf-8'))  # Send the data to the serial port

    print(c)  # Print the detected state
    return

# Function to draw lines detected in the frame
def drawLine(frame):
    edges = cv.Canny(frame, 50, 150, apertureSize=3)  # Perform edge detection
    cv.imshow('edges', edges)  # Show edges
    lines = cv.HoughLinesP(edges, 1, np.pi / 180, 100, minLineLength=100, maxLineGap=10)  # Detect lines
    f = 0
    if lines is not None:
        for line in lines:
            f = 1  # Line found
            x1, y1, x2, y2 = line[0]
            cv.line(frame_cc, (x1, y1), (x2, y2), (0, 255, 0), 2)  # Draw the line on the frame
    cv.imshow("aeh", frame_cc)  # Show the modified frame with lines
    return f  # Return whether a line was detected

# Function to get contours from a mask
def getContours(frame):
    contours, meow = cv.findContours(frame, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_NONE)  # Find contours
    x, y, w, h = 0, 0, 0, 0
    me = 0
    list = []  # List to store contour information
    for cnt in contours:
        area = cv.contourArea(cnt)  # Calculate contour area
        if area > 100:  # Filter out small contours
            cv.drawContours(frame_cc, cnt, -1, (255, 0, 0), 3)  # Draw contours on the original frame
            peri = cv.arcLength(cnt, True)  # Calculate perimeter of the contour
            approx = cv.approxPolyDP(cnt, 0.02 * peri, True)  # Approximate the contour
            x, y, w, h = cv.boundingRect(approx)  # Get bounding rectangle
            x = x + w / 2  # Center x-coordinate
            y = y + h / 2  # Center y-coordinate
            rect = [x, y, w, h]  # Store bounding rectangle info
            list.append(rect)  # Add to list of contours
    return list  # Return the list of detected contours

# Main loop for reading frames from the camera
while True:
    success, frame = test.read()  # Read a frame from the camera
    frame_cc = frame.copy()  # Create a copy of the frame for drawing
    findColor(frame, myColors, myColorValues)  # Find colors in the current frame
    cv.imshow("Result", frame_cc)  # Show the result frame

    # Exit loop if 'q' is pressed
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture and destroy all OpenCV windows
test.release()
cv.destroyAllWindows()
