//This code produces a "beep beep" every second.
// Pin 5 is the output
// It uses the tone function that produces a square signal with a duty cycle depending in the frequency of the tone.
// Autor: Antonio de Jesus Anaya Hernandez
// FabAcademy 2021
// Lab: Agrilab
// Country: France

void setup() {
}

void loop() {
  delay(1000);
  beep();
}

//This function produces a "beep" using Tone function in pin 5.
void beep(){
  tone(5, 4186, 85.5);
  delay(85.5);
	tone(5, 4186, 85.5);
  delay(85.5);
  noTone(5);
}
