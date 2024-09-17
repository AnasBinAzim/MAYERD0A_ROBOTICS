

import serial
import time

ser = serial.Serial("/dev/ttyACM0", 9600, timeout=1)

ser.setDTR(False)
time.sleep(1)
ser.flushInput()
ser.setDTR(True)
time.sleep(2)

while True:

	print('Telling the Arduino to start blinking...')
	cmd = "N"
	ser.write(cmd.encode())

	time.sleep(5)
	cmd = "G"

	ser.write(cmd.encode())

	time.sleep(1)
