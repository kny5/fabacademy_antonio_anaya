void setup() {
  Serial.begin(9600);
  /*Serial1.begin(9600);*/
  Wire.begin();
  sensor.begin();
}

void loop() {
Wire.beginTransmission(73);
Wire.write(byte(0x00));
Wire.endTransmission();

char rfid = Serial1.read();
Serial.println(rfid);
delay(100);

}
