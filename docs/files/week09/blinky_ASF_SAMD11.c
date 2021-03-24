/*
This program uses the SAM11.h library from the ASF programming repository at github.

IO pins:

PA02 <- Digital pull-up input
PA05 -> Digital LED output

This program reads PA02 to turn on the LED at PA05, and makes a bouncing-blinky effect like an fluorescent old lamp.

Nested while loops:
Loop1: Runs the whole program.
  Loop2: Waits until PA02 state changes, the change is made by pulsating the button on the board.
  Loop3: Toggles the LED state reducing the period every time.
  Loop4: Toggles the LED state increasing the period every time.
  If2: Keeps the LED on or off depending on the st variable, saves the value every in every cicle.

Autor: Antonio de Jesus Anaya Hernandez
Year: 2021
Org: Fab Academy
Lab: AgriLab
Country: France

*/
#include <samd11.h>
#define LED PORT_PA05
int cb = 200000;
double p = 0.7;
int st = 0;

void delay(uint32_t n) {
   uint32_t i = 0;
   while (i < n) ++i;
   }

int main(void) {
   //Clock Setup
   SYSCTRL->OSC8M.bit.PRESC = 1;

   //Configure PIN PA02 as digital input
   PORT->Group[0].PINCFG[2].reg |= PORT_PINCFG_INEN;
   PORT->Group[0].PINCFG[2].reg &= ~PORT_PINCFG_PULLEN;

   //Set LED pin PA05 as digital output
   REG_PORT_DIRSET0 = LED;

   // Loop_1
   while (1) {
     // Loop_2
     while (1){
       // Read PA02 state, halts the program until the button is pulsated
       if ((PORT->Group[0].IN.reg & PORT_PA02) < 1){
         if (st == 0){
           st = 1;
         } else { st = 0; }
         break; //Break to loop_3
       }
     }
     // Loop_3
     while (cb > 100) {
       // Decreases delay time
       cb = cb - (cb*p);
       //Toggle LED
       REG_PORT_OUTTGL0 |= LED;
       delay(cb);
     }
     // Loop_4
     while (cb < 300000){
       //Increases delay time
       cb = cb + (cb*p);
       // Toggle LED
       REG_PORT_OUTTGL0 |= LED;
       delay(cb);
     }
     if (st == 1){
       // Turn LED on
       REG_PORT_OUTSET0 |= LED;
       // Else turn LED off
     } else { REG_PORT_OUTCLR0 |= LED;}
   }
 }
