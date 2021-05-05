/*
  Reading a serial ASCII-encoded string.

  This sketch demonstrates the Serial parseInt() function.
  It looks for an ASCII string of comma-separated values.
  It parses them into ints, and uses those to fade an RGB LED.

  Circuit: Common-Cathode RGB LED wired like so:
  - red anode: digital pin 3
  - green anode: digital pin 5
  - blue anode: digital pin 6
  - cathode: GND

  created 13 Apr 2012
  by Tom Igoe
  modified 14 Mar 2016
  by Arturo Guadalupi

  This example code is in the public domain.
*/
void setup() {
  // initialize serial:-------------------------------
  Serial.begin(115200);
  Serial1.begin(115200);
  delay(200);
  Serial1.write("ATLED0=100");
  delay(500);
  Serial.println(Serial.read());
}

void loop() {

Serial1.write(Serial.read());

Serial.println(Serial1.read());

delay(100);
}
