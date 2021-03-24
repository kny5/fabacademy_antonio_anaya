/*---------------------------------------------------------------------------------------------------------------------------------------------------
   mcurses box demo

   Copyright (c) 2011-2015 Frank Meyer - frank(at)fli4l.de

   Revision History:
   V1.0 2015 xx xx Frank Meyer, original version
   V1.1 2017 01 14 ChrisMicro, converted to Arduino example

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
  ---------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include "mcurses.h"

#define         myitoa(x,buf)                   itoa ((x), buf, 10)

int buttonState = 0;

char PROGMEM logoFab[] = "\r\            ######## ########\n\
\r\        ########          #######\n\
\r\      ###################     ######\n\
\r\     ##      ##############       ###\n\
\r\   ((         #############         %%%\n\
\r\  (((            /#####             %%%\n\
\r\ ((((                               %%%%\n\
\r\ ((((   (((((((           %%%%%%%%%%%%%%\n\
\r\ ((((   (((((((((       &%%%%%%%%%%%%%%%\n\
\r\  (((   ((((((((((     &%%%%%%%%%   %%%*\n\
\r\   ((    (((((((((     %%%%%%%%%    %%%\n\
\r\    (((   (((((((       (%%%%%    %%%\n\
\r\      ((((((((((              %%%%%%\n\
\r\        ((((((((          %%%%%%%\n\
\r\            (((((((( %%%%%%%%\n\
";

void Arduino_putchar(uint8_t c)
{
  Serial.write(c);
}

void setup()
{
  Serial.begin(115200);

  setFunction_putchar(Arduino_putchar); // tell the library which output channel shall be used

  initscr();                  // initialize mcurses

  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop()
{
  buttonState = digitalRead(2);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(5, HIGH);
    mvaddstr_P (18, 0, PSTR("fabacademy.org"));
    mvaddstr_P (20, 0, PSTR("This is an example of MCURSES a NCURSES library for microcontrollers"));
  } else {
    // turn LED off:
    digitalWrite(5, LOW);

  }
  char    buf[10];
  uint8_t idx;
  mvaddstr_P (0, 0, PSTR(logoFab));
  delay(500);
  clear ();
  
}
