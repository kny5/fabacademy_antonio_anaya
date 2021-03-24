/*
This program uses Arduino and Mouse library.
This program reads the board button to scroll-down and after the release of the button waits for 4 seconds to scroll up. After 4 seconds the program waits for a new button push event.

IO pins:
PA02 <- Digital pull-up button input
PA05 -> Digital LED output

Autor: Antonio de Jesus Anaya Hernandez
Year: 2021
Org: Fab Academy
Lab: AgriLab
Country: France
*/

#include <Mouse.h>

// Adding BTN and LED constant values, 2 for PA02 and 5 for PA05.
const int BTN = 2;
const int LED =  5;
// This is the cycle speed of the program it's required to avoid overpowerful scrolls.
const int speed = 50;
// This is the Button state variable and it will constantly change in the program.
int btn_state = 0;

// This is a function for blink, made with analogwrite to make a pulse effect in the light.
void blink() {
  //this is a FOR cycle and it repeats the code inside it by a number of defined cycled in a counter.
  // pw is the counter and it increases by 1 at every cycle count.
  // the cycle will end if PW is equal to 255.
  // 255 is the resolution of the PWM analogWrite function. so 254 is equal to digital HIGH and 0 to LOW.
  for(int pw = 0; pw < 255; pw++){
      delay(1);
      // Increase the LED power output
      analogWrite(LED,pw);
  }
  // Turn off the LED
  analogWrite(LED,0);
}

// This code is the setup for the starting condicionts of the program. This is only executed at powerup.
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Mouse.begin();
  //Serial.begin(9600);
}

// This is the program Loop and this code will be repeated if it's not halted.
void loop() {
  // This is the value for the light power output at idle state.
  analogWrite(LED,5);
  btn_state = digitalRead(BTN);
  // if the button is pressed the idle cycle ends and it enters to the button pressed Loop.
  if(btn_state == LOW){
    // while the button is pressed this cycle will repeat
    while(btn_state == LOW){
      //delay pause
      delay(speed);
      // Turn on the light
      analogWrite(LED, 100);
      // Move the mouse wheel by -1, in Linux and windows this means DOWN in MAC it means UP
      Mouse.move(0,0,-1);
      // Check the button status, if released breaks the cycle. And goes to the next one.
      btn_state = digitalRead(BTN);
    }
    // This cycle contains a counter, to access to multiple functionalities with only one button. It waits for a pulse input for a specified ammount of milliseconds.
    // The time is realative ti the system so for most systems this will be close to 3 seconds.
    // In this cycle we have a counter and if the button is pressed before 3 seconds it will enter the Scroll-UP cycle.
    for(int clicks = 0; clicks < 10; clicks++){
      delay(speed);
      //Serial.println("Clicked");
      //Serial.print(clicks);
      if(clicks < 6){
        //digitalWrite(LED, HIGH);
        blink();
      }
      btn_state = digitalRead(BTN);
      // This is the scroll-Down cycle.
      while(btn_state == LOW && clicks < 6){
        delay(speed);
        //analogWrite(LED,30);
        // Move the mouse wheel by 1 it means Scrooll UP in windows and Linux and scroll down in MAC.
        Mouse.move(0,0,1);
        btn_state = digitalRead(BTN);
      }
    }
  }
  //delay(speed);
  //Serial.println("waitting");
}
