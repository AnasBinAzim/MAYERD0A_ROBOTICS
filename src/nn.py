# importing the module
import cv2

# reading the video
source = cv2.VideoCapture(0)

# running the loop
while True:

    # extracting the frames
    ret, img = source.read()

    # converting to gray-scale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

    # displaying the video
    cv2.imshow("Live", img)

    # exiting the loop
    key = cv2.waitKey(1)
    if key == ord("q"):
        break

# closing the window
cv2.destroyAllWindows()
source.release()
