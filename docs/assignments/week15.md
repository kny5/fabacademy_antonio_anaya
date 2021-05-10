# 15. Interface and application programming

## introduction

For this week I've decided to complete the minimum requirements. My tasks will be:

1. Use the 134KHz RFID sensor.
1. Optionally use an FDX and HDX sensor to read cow RFID tags used in France and Mexico.
2. Give a format to the data received in the mircro-controller code, form the sensor.
2. Establish serial communication between micro-controller and computer.
3. Read and parse the data received from microcontroller using Python.
4. Make a short basic UI. Using QT.
5. Make a distributable version of the software using a packaging library.



## Micro-controller

I've used again my [board from week 11](../../assignments/week11).

```
// This code uses:

// Pin 31 for Serial communication at 9600 bauds
// 5 Volts for RFID Tag reader board

// Communication protocols: USB Serial abd "Serial1 interface" for RFID tag reader.

// This code reads the RFID tag and prints the result in SERIAL.

// Autor: Antonio de Jesus Anaya Hernandez
// Fab-Academy: 2021 Agrilab
// Country: France

/*#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
*/
char rfid_tag [30];

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  /*
  Wire.begin();
  lcd.init();
  lcd.backlight();
  */
}

void loop() {
  int id = Serial1.read();

  if (id == 2){
    //beep();
    //rfid_tag[0] = id;
    for (int c = 0; c < 26; c++){
      int bit_ = Serial1.read();
      rfid_tag[c] = bit_;
   }
   Serial.println(rfid_tag);
   }

  /*
  lcd.setCursor(0,0);
  lcd.print(rfid_tag);
  */

  delay(200);

}
```


## Python

The Python programming language it's my favorite programming language. So I've decided to skip a trial of multiple programming languages and just use the one I like the most.



### About Python




### Configurations




####  Conda environment

Creating a new environment:

```
conda create -n week15
```

Activate environment:

```
conda activate week15
```

Install pyserial:

```
pip install pyserial
```

First trial code:

```
import serial
baud_rate = 9600
port = '/dev/ttyUSB0'


# device = serial.Serial(port)
with serial.Serial(port, baud_rate, timeout=1) as serial_device:
    print(serial_device.name)
    data = serial_device.readline()

while(True):
    print(data)
```

Second trial code:

```
import serial
import time

print("This program reads the Serial port /dev/ttyACM0 at 9600 bauds and prints the output using the readline serial function on pyserial library. /dev/ttyACM0 its my board based on the ATSAMD11 microcontroller and it has connected in Serial2 the 134KHz RFID FDX tag reader board.")

baud_rate = 9600
port = '/dev/ttyACM0'
milking = True

def parse_rfid(rfid_code):
    head = rfid_code[:1]
    code = rfid_code[1:11]
    country = rfid_code[11:14]
    tail = rfid_code[14:]
    return (head, code, country, tail)

# device = serial.Serial(port)
with serial.Serial(port, baud_rate, timeout=10) as serial_device:
    dev_name = serial_device.name
    print(dev_name)

    while(milking):
        time.sleep(0.5)
        data = serial_device.readline()
        if len(data) > 3:
            try:
                data_decoded = data.decode('utf-8')
                print("The RFID scanned tag code is: ", parse_rfid(data_decoded))
                data = None
            except UnicodeDecodeError:
                print("Scan again")
        else:
            print("No tags detected")
```
