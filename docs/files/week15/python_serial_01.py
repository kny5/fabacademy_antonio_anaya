# print("This program reads the Serial port /dev/ttyACM0 at 9600 bauds and prints the output using the readline serial function on pyserial library. /dev/ttyACM0 its my board based on the ATSAMD11 microcontroller and it has connected in Serial2 the 134KHz RFID FDX tag reader board."

import serial
import time
import logging


baud_rate = 9600
port = '/dev/ttyACM0'
output = "Default"


def hex_to_dec(data):
    reversed = data[::-1]
    decimal = int(reversed, 16)
    return str(decimal)


def parse_rfid(rfid_code):
    head = rfid_code[:1]
    code = rfid_code[1:11]
    country = rfid_code[11:14]
    tail = rfid_code[14:]
    return "{code}, {country}".format(code=hex_to_dec(code), country=hex_to_dec(country))


def try_serial():
    try:
        with serial.Serial(port, baud_rate, timeout=10) as serial_device:
            dev_name = serial_device.name
            print(dev_name)
            serial_device.close()
            return True
    except:
        print("No conection")
        return False


def read_rfid():
    try:
        with serial.Serial(port, baud_rate, timeout=10) as serial_device:
            dev_name = serial_device.name
            print(dev_name)
            data = serial_device.readline()
            if len(data) > 3:
                try:
                    data_decoded = data.decode('utf-8')
                    output = "The RFID scanned tag code is: %s" % parse_rfid(data_decoded)

                except UnicodeDecodeError:
                    output = "Scan again"
            else:
                output = "No tags detected"
            print(output)
            serial_device.close()
            return output
    except:
        return "Not connected"
