/*
This program reads the analog output of a HALL effect A-1324 sensor to millivolts

Pinout:

Hall sensor @ PIN 4

Pseudo-code:

First declares the constants "HALL" to 4, "VIN_FACTOR" the factor of conversion to analog to millivolts 3.3/1023.

Declares a long precision variable "value".

Sets Hall pin as input, and starts Serial (USB) communication at 9600 bauds.

Loops analog read of HALL and sends TX Serial with the result of Value times VIN_FACTOR.

Autor: Antonio de Jesus Anaya Hernandez
Agrilab, France.
Fabacademy week 11.

*/

const int HALL = 4;
const long VIN_FACTOR = 3.3 / 1.023 ;
long value = 0;

void setup() {
  pinMode(HALL, INPUT);
  Serial.begin(9600);
}

void loop() {

value = analogRead(HALL);

Serial.println(value * VIN_FACTOR);

}
