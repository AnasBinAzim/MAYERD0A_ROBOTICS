import serial
import time
ser = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)

ser.setDTR(False)
time.sleep(1)
ser.flushInput()
ser.setDTR(True)
time.sleep(2)

while True:
	num = 3
	str = f"{num}"
	ser.write(str.encode('utf-8'))
	num = 6
	str = f"{num}"
	ser.write(str.encode('utf-8'))
	
