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
  noTone(5);
}
