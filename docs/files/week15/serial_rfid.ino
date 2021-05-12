//This code uses:
// LiquidCrystal_I2C and Wire library.
// Pins 14 and 15 as SDA and SCL.
// Pin 31 for Serial communication at 9600 bauds
// Pin 5 for tone speaker output
// 5 Volts for RFID Tag reader board
// 3.3 Volts for Speaker and LCD display.
// Communcation protocols: i2c for display and Serial at "Serial1 interface" for RFID tag reader.
// This code makes the i2c display blink its backlight for 1 second and writes "hello" during setup and "world" during loop.
// Autor: Antonio de Jesus Anaya Hernandez
// Fab-Academy: 2021 Agrilab
// Country: France

char rfid_tag [26];

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  byte id = Serial1.read();
  
  rfid_tag[0] = id;
  
  if (id == 2){
    for (int c = 1; c < 26; c++){
      byte bit_ = Serial1.read();
      rfid_tag[c] = bit_;
      }
  Serial.println(rfid_tag);
  }
  
  //Serial.println(id); 
  delay(200);
/*
99                                                                                                                   
246                                                                                                                  
22                                                                                                                   
125                                                                                                                  
155                                                                                                                  
159                                                                                                                  
155                                                                                                                  
159
147
159
159
159
159
157
155
229
0

179
217
22
125
159
155
145
159
143
159
143
143
145
159
153
229
0
*/
}
