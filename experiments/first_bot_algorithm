import cv2 as cv  # Import OpenCV library
import numpy as np  # Import NumPy for numerical operations

# Initialize video capture from the first camera (0)
temp = cv.VideoCapture(0)

# Set the desired width and height for the video capture
frameWidth = 1080
frameHeight = 320
temp.set(3, frameWidth)  # Set frame width
temp.set(4, frameHeight)  # Set frame height
temp.set(10, 30)  # Set the brightness (if applicable)

# Function to resize the frame to a specified scale
def resize_frame(framee, scale=0.25):
    # Resize the frame to 320x240 pixels
    fr = cv.resize(framee, (320, 240))
    return fr  # Return the resized frame

# Placeholder function for trackbar callback (currently does nothing)
def aeh(a):
    pass

# Create a window named "HSV" for HSV tracking
cv.namedWindow("HSV")
cv.resizeWindow("HSV", 640, 240)  # Set window size

# Create trackbars for HSV color range adjustment
cv.createTrackbar("H Min", "HSV", 0, 179, aeh)  # Minimum Hue
cv.createTrackbar("H Max", "HSV", 179, 179, aeh)  # Maximum Hue
cv.createTrackbar("S Min", "HSV", 0, 255, aeh)  # Minimum Saturation
cv.createTrackbar("S Max", "HSV", 255, 255, aeh)  # Maximum Saturation
cv.createTrackbar("V Min", "HSV", 0, 255, aeh)  # Minimum Value (Brightness)
cv.createTrackbar("V Max", "HSV", 255, 255, aeh)  # Maximum Value (Brightness)

# Main loop to read frames and process them
while True:
    isTrue, framee = temp.read()  # Read a frame from the video capture
    frame = resize_frame(framee, 0.5)  # Resize the frame
    frameHsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)  # Convert the frame to HSV color space
    cv.imshow("Rakib", frameHsv)  # Display the HSV frame

    # Retrieve the current position of each trackbar
    h_min = cv.getTrackbarPos("H Min", "HSV")
    h_max = cv.getTrackbarPos("H Max", "HSV")
    s_min = cv.getTrackbarPos("S Min", "HSV")
    s_max = cv.getTrackbarPos("S Max", "HSV")
    v_min = cv.getTrackbarPos("V Min", "HSV")
    v_max = cv.getTrackbarPos("V Max", "HSV")

    # Create lower and upper bounds for color masking
    lower = np.array([h_min, s_min, v_min])  # Lower HSV bounds
    upper = np.array([h_max, s_max, v_max])  # Upper HSV bounds

    # Create a mask based on the defined HSV range
    mask = cv.inRange(frameHsv, lower, upper)
    # Apply the mask to get the result image
    result = cv.bitwise_and(frame, frame, mask=mask)

    # Convert the mask to BGR format for display
    mask = cv.cvtColor(mask, cv.COLOR_GRAY2BGR)
    cv.imshow("end", mask)  # Show the mask image

    # Stack the original frame, mask, and result image horizontally
    hStack = np.hstack([frame, mask, result])
    cv.imshow('Horizontal Stacking', hStack)  # Display the stacked images

    # Exit loop if 'q' is pressed
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Release the video capture and destroy all OpenCV windows
temp.release()
cv.destroyAllWindows()
