import serial
import time

from signal import signal, SIGINT
from sys import exit

# name of file to save data
filename = 'saved_data.csv'

myFile = open(filename, "w")


# Handler for singal
def handler(signal_received, frame):
    # Handle any cleanup here
    myFile.close()
    exit(0)


# register handler
signal(SIGINT, handler)

# serial port name. Change based upon operating system
# portName='/dev/cu.usbmodem1461301'
portName = 'COM5'

# com port baud rate
baudRate = 9600

# attempt to open serial port
ser = serial.Serial(portName, baudRate)
print("Opening port " + ser.name)

if ser.is_open:
    print("Success!")
else:
    print("Unable to open port :(")

print("Running a demo for 10s...")
startTime = currentTime = int(time.time())

# use this version of the loop to save for some amount of time
# while abs(currentTime-startTime) < 10:

# use this version of the loop to operate continuously until break is received
while True:
    ### Below are two demo programs for read from serial. Run only one
    ### of these at a time so additional data is not "accidentally" read.

    #### Demo #1 ####
    ## read only a single byte, not really that useful
    # byte = ser.read()
    ## convert to string and strip out all new line characters
    # string = str(byte.decode('utf-8')).replace('\r', '').replace('\n', '')
    # print(string)

    #### Demo #2 ####
    ##read until line and strip out \r\n terminators
    bytes = ser.readline()
    # decode bytes into string
    line = bytes.decode('utf-8')
    line = line.replace('\r', '').replace('\n', '')
    print(line)
    myFile.write(line)

    currentTime = int(time.time())

print("Show's over. Close the port!")
myFile.close()
ser.close()
