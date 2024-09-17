import cv2

# Open the camera (0 is the default camera)
cap = cv2.VideoCapture(0)

# Check if the camera opened successfully
if not cap.isOpened():
    print("Error: Could not open camera.")
    exit()

# Set desired frame rate (e.g., 30 FPS)
desired_fps = 20
cap.set(cv2.CAP_PROP_FPS, desired_fps)

# Print the actual frame rate
actual_fps = cap.get(cv2.CAP_PROP_FPS)
print(f"Actual FPS: {actual_fps}")

while True:
    # Capture frame-by-frame
    ret, frame = cap.read()

# If the frame is not read correctly, break the loop
    if not ret:
        break

# Display the resulting frame
    cv2.imshow('Frame', frame)

# Break the loop when 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the capture and close windows
cap.release()
cv2.destroyAllWindows()