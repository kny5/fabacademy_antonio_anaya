#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

char rfid_tag [30];

void setup() {
  Wire.begin();
  Serial1.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  int id = Serial1.read();

  if (id == 2){
    beep();
    rfid_tag[0] = id;
    for (int c = 1; c < 30; c++){
      int bit_ = Serial1.read();
      rfid_tag[c] = bit_;
    }
    }
  lcd.setCursor(0,0);
  lcd.print(rfid_tag);
}

void beep(){
  tone(5, 4186, 85.5);
  delay(85.5);
  noTone(5);
}
