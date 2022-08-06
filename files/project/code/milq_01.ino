/*
This program uses the arduino IDE compile tools.

This program plots an horizontal graph to visualize step response reading analog signals from PIN_04 with 12 bits resolution.
On PIN_02 (DAC0) its emitted an analog signal that later will be transmitted using the probe board to liquids to measure the conductivity of it.

Conductivity increases or decreases depending in the substance so, its possible to observe a step response signal in the horizontal graph.
The program runs a cycle of n number of samples, saves the results of every sample on an array and then shows the average value.

It also shows a custom character for the AgriLab logo.

IO pins:
PA02 -> DAC0 analogWrite
PA05 <- analogRead

Autor: Antonio de Jesus Anaya Hernandez
Year: 2021
Org: Fab Academy
Lab: AgriLab
Country: France
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

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

void setup() {
  Wire.begin();
  Serial.begin(9600);

  mkr_chrs();

  lcd.init();
  lcd.backlight();

  lcd.createChar(7, customChar);

  bootstart_msg();

  animation_01(50);
  lcd.clear();
  pinMode(4, INPUT);
  analogReadResolution(12);
  analogWriteResolution(12);
}

void loop() {

  byte SAMPLES[sample_size-1];
  int mult = sample_size/20;
  lcd.setCursor(12,0);
  agrilab();


  for(int s = 0; s < sample_size; s++){
    analogWrite(DAC0, max_val);
    int ec_val = analogRead(4);

    lcd.setCursor(8,3);
    lcd.print(ec_val);
    SAMPLES[s] = ec_val;

    plot(ec_val, s/mult);

    lcd.setCursor(s/mult,3);
    lcd.print(">");

    lcd.setCursor(0,3);
    lcd.print(s+1);
    }

  int sum_ec = 0;

  for(int z = 0; z < sample_size; z++){
    sum_ec += SAMPLES[z];
   }

   lcd.setCursor(17,3);
   lcd.print(sum_ec/sample_size);
   delay(3000);
   lcd.clear();
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
