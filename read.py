import serial
import time

ser = serial.Serial('/dev/ttyACM0', 9600, timeout=0.1);
if ser.isOpen():
	ser.close()
ser.open()
time.sleep(1)

with open('dump.bin','wb') as f:
	while True:
		try:
			x = ser.readline()
			print x.strip()
			f.write(x)
			f.flush()
			time.sleep(0.1)
		except serial.serialutil.SerialException:
			pass
		

