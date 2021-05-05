// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  lcd.init();
  lcd.setCursor(1,1);
  lcd.clear();
  lcd.print("Students board:");
  lcd.backlight();
}

byte x = 0;

void loop()
{
  Wire.begin();
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  x++;
  delay(500);
  Wire.onReceive(students_say);
}


void students_say(int here)
{
  while (1 < Wire.available()) {
    char c =  Wire.read();
    Serial.print(c);
    lcd.setCursor(0,0);
    lcd.print(c);
    }
  int x = Wire.read();
  Serial.println(x);
  }
