#include "AS726X.h"

AS726X sensor;

void setup() {
  Serial.begin(9600);
  /*Serial1.begin(9600);*/
  Wire.begin();
  sensor.begin();
}

void loop() {
/*
Wire.beginTransmission(73);
Wire.write(byte(0x00));
Wire.endTransmission();

char rfid = Serial1.read();
Serial.println(rfid);
delay(100);
*/
sensor.takeMeasurements();
  //Prints all measurements
    //Visible readings
    Serial.print(" Reading: V[");
    Serial.print(sensor.getCalibratedViolet(), 2);
    Serial.print("] B[");
    Serial.print(sensor.getCalibratedBlue(), 2);
    Serial.print("] G[");
    Serial.print(sensor.getCalibratedGreen(), 2);
    Serial.print("] Y[");
    Serial.print(sensor.getCalibratedYellow(), 2);
    Serial.print("] O[");
    Serial.print(sensor.getCalibratedOrange(), 2);
    Serial.print("] R[");
    Serial.print(sensor.getCalibratedRed(), 2);

}
