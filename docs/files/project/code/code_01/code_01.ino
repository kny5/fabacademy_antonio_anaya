//#include <hd44780.h>


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

char rfid_tag[26];

#define max_val 4000
#define sample_size 100
#define duty_cycle 1
#define lcd_scaler 2
#define lcd_segments 8
#define plot_mult ((max_val / lcd_segments)*2) * duty_cycle

uint8_t customChar[8] = {
  0x02,
  0x0A,
  0x0E,
  0x1E,
  0x1E,
  0x1C,
  0x0C,
  0x08
};

void mkr_chrs(){
  lcd.init();
  lcd.setCursor(0,0);

  uint8_t graphChar[8][8] = {B00000};

  for(int n = 0; n<7; n++){
  graphChar[n][n] = B11111;
  lcd.createChar(n, graphChar[n]);
  }};

void plot(int a, int c_pos){
   int a_p = (max_val - a) / plot_mult;
   
   lcd.home();
   lcd.print(a_p);

   if(a_p == 7){
    lcd.setCursor(c_pos,2);
    lcd.print("_");
    }
   else if(a_p < 5){
    lcd.setCursor(c_pos,1);
    lcd.write(a_p*lcd_scaler);
    }
   else {
    lcd.setCursor(c_pos,2);
    lcd.write(a_p*lcd_scaler);}
   };

void p_samples(){
  for(int n = 0; n < 8; n++){
    lcd.setCursor(2+n, 0);
    lcd.write(n);
    }
  }

void setup() {
  Wire.begin();
  Serial.begin(9600);

  mkr_chrs();

  lcd.init();
  lcd.backlight();

  lcd.createChar(7, customChar);

  //bootstart_msg();
  //delay(1000);
  animation_01(50);
  lcd.clear();
  pinMode(4, INPUT);
  //pinMode(5, OUTPUT);
  pinMode(5, INPUT);
  analogReadResolution(12);
  analogWriteResolution(12);
}

void loop() {

  /*
  String keys = btn_cal();

  for(int count = 0; count < 3; count++)
  { 
    lcd.setCursor(count,count);
    lcd.print(keys[count]);
    delay(1000);
    }
  
  if (Serial1.available()) {
    animation_01(100);
    lcd.setCursor(0,1);
    char* rfid_val = readRFIDtag();
    lcd.print(rfid_val);
    delay(1000);
  }
  else{
    lcd.print("nope");
    }
  */

  //p_samples();


  byte SAMPLES[sample_size-1];
  int mult = sample_size/20;
  lcd.setCursor(12,0);
  agrilab();

  
  for(int s = 0; s < sample_size; s++){
    //digitalWrite(5, HIGH);
    analogWrite(DAC0, max_val);
    int ec_val = analogRead(4);
    //analogWrite(DAC0, 0x0);

    lcd.setCursor(8,3);
    lcd.print(ec_val);
    SAMPLES[s] = ec_val;


    //lcd.setCursor(s/mult,2);
    plot(ec_val, s/mult);

    lcd.setCursor(s/mult,3);
    lcd.print(">");

    lcd.setCursor(0,3);
    lcd.print(s+1);
    //digitalWrite(5, LOW);
    }

  int key = analogRead(5);

    lcd.setCursor(3,0);
    if(key > 640){
      lcd.print("c");
      }
    else if(key > 520 && key < 550){
      lcd.print("b");
      }
    else if(key < 250 && key > 350){
      lcd.print("a");
      }
    else{
      lcd.print("?");
      }
    lcd.setCursor(5,0);
    lcd.print(key);
    
    
  int sum_ec = 0;

  for(int z = 0; z < sample_size; z++){
    sum_ec += SAMPLES[z];
   }
   lcd.setCursor(17,3);
   lcd.print(sum_ec/sample_size);
   delay(3000);

   lcd.clear();
}


char* readRFIDtag() {
  byte id = Serial.read();
  rfid_tag[0] = id;

  if (id == 2){
    for (int c = 1; c < 26; c++){
      byte bit_ = Serial.read();
      rfid_tag[c] = bit_;
      }
  }
  return rfid_tag;
  }

void agrilab(){
  const char a[] = {"AgriLab"};
  lcd.print(a);
  lcd.write(7);
  }

void bootstart_msg() {

  const char b[] = {"Fab Academy 2021"};
  const char c[] = {"MILQ"};

  lcd.setCursor(6,1);

  agrilab();
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(b);
  lcd.setCursor(0,2);
  lcd.print(c);
  delay(3000);
  }

void animation_01(int del_ay){
  int a;
  int b;
  for(a = 0; a < 20; a++){
    lcd.setCursor(a,3);
    lcd.print("/");
    delay(del_ay);
    }
  }

void dieleric_01(){
  while(true){
    analogWrite(DAC0, 0xff);
    analogWrite(DAC0, 0x0);
    }
  }

void die_read_02(){
  while(true){
    lcd.print(analogRead(4));
    }
  }

String cal_msg(String ltr){
  return "Press the key " + ltr;
  } 

String btn_cal(){
  String lts = "ABC";
  char btns[3] = {0};
  
  while(true){
    lcd.setCursor(0,0);
    lcd.print("Calibration process...");

    for(int count = 0; count <3; count++){
      lcd.setCursor(0,1);
      String ltr = String(lts[count]);
      String msg = cal_msg(ltr);
      lcd.print(msg);
      delay(1000);
      int read_btn = analogRead(5);
      delay(1000);
      
      if(read_btn > 1000){
        btns[count] = read_btn;
        delay(1000);
      }
      
      else {
        lcd.clear();
        lcd.home();
        lcd.print(read_btn);
        delay(3000);
        continue;
        }
      }
      lcd.print(btns);
      continue;
    }
  return btns;    
  }
