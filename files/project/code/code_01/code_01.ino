#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#define max_val 4000
#define sample_size 500
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

  for(short n = 0; n<7; n++){
  graphChar[n][n] = B11111;
  lcd.createChar(n, graphChar[n]);
  }};

void plot(short a, short c_pos){
   short a_p = (max_val - a) / plot_mult;

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

void setup() {
  Wire.begin();
  Serial1.begin(9600);

  mkr_chrs();

  lcd.init();
  lcd.backlight();

  lcd.createChar(7, customChar);

  bootstart_msg();
  delay(1000);
  animation_01(20);
  lcd.clear();
  pinMode(4, INPUT);
  analogReadResolution(12);
  analogWriteResolution(12);
}

void loop() {
  rfid_msg();
  while(true){
    if(read_rfid() == false){
      break;
      }
    }

  short SAMPLES[sample_size-1];
  short mult = sample_size/20;
  lcd.setCursor(12,0);
  agrilab();

  delay(500);

  for(short s = 0; s < sample_size; s++){
    analogWrite(DAC0, max_val);
    short ec_val = analogRead(4);
    analogWrite(DAC0, 0x0);

    lcd.setCursor(8,3);
    lcd.print(ec_val);
    SAMPLES[s] = ec_val;

    plot(ec_val, s/mult);

    lcd.setCursor(s/mult,3);
    lcd.print(">");

    lcd.setCursor(0,3);
    lcd.print(s+1);
  }

  short sum_ec = 0;

  for(short z = 0; z < sample_size; z++){
    sum_ec += SAMPLES[z];
  }
    lcd.clear();
    lcd.setCursor(12,0);
    agrilab();
    lcd.setCursor(16,3);
    lcd.print(sum_ec/sample_size);
    delay(5000);
    lcd.clear();
}

void agrilab(){
  const char a[] = {"AgriLab"};
  lcd.print(a);
  lcd.write(7);
}

void rfid_msg(){

  lcd.home();
  lcd.print("To Start");
  lcd.setCursor(0,1);
  lcd.print("Please scan a valid");
  lcd.setCursor(0,2);
  lcd.print("RFID FDX tag...");
}


void bootstart_msg() {

  lcd.setCursor(6,1);
  agrilab();
  delay(1000);

  lcd.clear();
  lcd.setCursor(5,1);
  lcd.print("Fab");
  lcd.setCursor(5,2);
  lcd.print("Academy");
  lcd.setCursor(8,3);
  lcd.print("2021");
  delay(2000);
  lcd.clear();
  lcd.home();
  lcd.print("MILQ");
  delay(2000);
  lcd.clear();
}


void animation_01(short del_ay){
  short a;
  short b;
  for(a = 0; a < 20; a++){
    lcd.setCursor(a,3);
    lcd.print("/");
    delay(del_ay);
    }
}


unsigned long long convert(char num[]) {
   short len = 10;
   unsigned long long base = 1;
   unsigned long long temp = 0;

   for (short i=len-1; i>=0; i--) {

      if (num[i]>='0' && num[i]<='9') {
         temp += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temp += (num[i] - 55)*base;
         base = base*16;
      }
   }
   return temp;
}


char rfid_tag [9];


bool read_rfid(){
  byte id = Serial1.read();
  rfid_tag[-1] = id;

  if (id == 2){
    for (short c = 8; c >=0; c--){
      byte bit_ = Serial1.read();
      rfid_tag[c] = bit_;
      }

  unsigned long long num = convert(rfid_tag);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(num);
  return false;
  }
  delay(100);
}
