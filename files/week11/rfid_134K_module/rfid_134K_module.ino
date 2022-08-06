/*
This program reads the TX output of the RFID ISO11784 for animal Tag FDX reading board, using the Serial1 interface of the SAMD11 micro-controller.

TX to RX on pin 31 Serial1


Autor: Antonio de Jesus Anaya Hernandez
Agrilab, France.
Fabacademy week 11.
*/

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  char id = Serial1.read();
  Serial.println(id);
  delay(100);
}
