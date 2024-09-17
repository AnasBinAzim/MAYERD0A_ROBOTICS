import cv2 as cv
import numpy as np
from numpy.f2py.auxfuncs import istrue
from numpy.ma.core import resize

# Capture video from the default camera (usually the webcam).
temp = cv.VideoCapture(0)


# Function to resize the frame, with a default scaling factor of 0.25.
def resize_frame(framee, scale=0.25):
    # Resize the frame to fixed dimensions (480x380) instead of scaling based on the original frame size.
    fr = cv.resize(framee, (480, 380))
    return fr


# Empty function used as a placeholder for the trackbar callback.
def aeh(a):
    pass


# Create a window named "HSV" and set its dimensions to 640x240.
cv.namedWindow("HSV")
cv.resizeWindow("HSV", 640, 240)

# Create trackbars for Hue, Saturation, and Value (HSV) ranges.
# These trackbars allow dynamic adjustment of HSV range for color filtering.
cv.createTrackbar("H Min", "HSV", 0, 179, aeh)  # Minimum hue value.
cv.createTrackbar("H Max", "HSV", 179, 179, aeh)  # Maximum hue value.
cv.createTrackbar("S Min", "HSV", 0, 255, aeh)  # Minimum saturation value.
cv.createTrackbar("S Max", "HSV", 255, 255, aeh)  # Maximum saturation value.
cv.createTrackbar("V Min", "HSV", 0, 255, aeh)  # Minimum value (brightness).
cv.createTrackbar("V Max", "HSV", 255, 255, aeh)  # Maximum value (brightness).

# Loop to continuously capture frames and process the video feed.
while True:
    # Capture each frame from the video feed.
    isTrue, framee = temp.read()

    # Resize the captured frame using the resize_frame function.
    frame = resize_frame(framee, 0.5)

    # Convert the frame from RGB to HSV color space.
    frameHsv = cv.cvtColor(frame, cv.COLOR_RGB2HSV)

    # Display the HSV converted frame in a window called "Rakib".
    cv.imshow("Rakib", frameHsv)

    # Get the current positions of the trackbars for Hue, Saturation, and Value ranges.
    h_min = cv.getTrackbarPos("H Min", "HSV")
    h_max = cv.getTrackbarPos("H Max", "HSV")
    s_min = cv.getTrackbarPos("S Min", "HSV")
    s_max = cv.getTrackbarPos("S Max", "HSV")
    v_min = cv.getTrackbarPos("V Min", "HSV")
    v_max = cv.getTrackbarPos("V Max", "HSV")

    # Define the lower and upper bounds for HSV based on the trackbar values.
    lower = np.array([h_min, s_min, v_min])
    upper = np.array([h_max, s_max, v_max])

    # Create a mask that isolates the colors in the HSV range defined by the trackbars.
    mask = cv.inRange(frameHsv, lower, upper)

    # Apply the mask to the original frame to extract the desired color range.
    result = cv.bitwise_and(frame, frame, mask=mask)

    # Convert the mask to a BGR image for easier visualization.
    cv.imshow("end", mask)

    # Stack the original frame, mask, and result horizontally for easy comparison.
    hStack = np.hstack([frame, mask, result])

    # Display the horizontally stacked images in a window.
    cv.imshow('Horizontal Stacking', hStack)

    # If the 'q' key is pressed, break the loop and end the program.
    if cv.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close all OpenCV windows.
temp.release()
cv.destroyAllWindows()
