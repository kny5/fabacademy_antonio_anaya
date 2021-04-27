# 13. Output Devices

## Introduction

This week I've started to use output devices that are part of my device for the final project.

- A **Speaker** to make a sound after a RFID successful read.
- A **LCD display** to show information relative to the milk production.

Then to make this possible I've listed here different components and concepts that were useful for me during this weeks work.


<img src="../../images/week12/outputs_02.jpg" alt="outputs_02.jpg" width=100%/>

<img src="../../images/week12/outputs_01.jpg" alt="outputs_01.jpg" width=100%/>


### 2N2222 Transistor

I've used the 2N2222 which is a multipurpose NPN transistor for low power amplification.

- For testing I've used the T0-92 form
- In my SMD circuit the SOT-23 form.

Datasheets:

- [P2N2222A](../../datasheets/P2N2222A.PDF)
- [MMBT2N2222A](../../datasheets/MMBT2N2222A.pdf)

<img src="../../images/week12/IMG_20210422_171541.jpg" alt="IMG_20210422_171541.jpg" width=100%/>

### Voltage divider

> *from Sparkfun's tutorial's page*

> *[https://learn.sparkfun.com/tutorials/voltage-dividers/all](https://learn.sparkfun.com/tutorials/voltage-dividers/all)*

> *"A voltage divider is a simple circuit which turns a large voltage into a smaller one. Using just two series resistors and an input voltage, we can create an output voltage that is a fraction of the input. Voltage dividers are one of the most fundamental circuits in electronics. If learning Ohm's law was like being introduced to the ABC's, learning about voltage dividers would be like learning how to spell cat."*

Why do I need this?

The RFID board that I'm using for my project uses 5 to 9 Volts for power source, while my projects micro-controller with the SAMD11E17 needs only 3.3 Volts.

<img src="../../images/week13/rfid_01.jpg" alt="rfid_01" width=100%/>

It means that to use this board with the UART Serial Communication Protocol, I need to connect the PIN_31 (RX) of my micro-controller to the TX pin of the RFID board.

So I need to convert from 5 to 3.3 Volts using a **Voltage divider**.

My current voltage divider configuration works using a 2k Ohms and 1 k Ohms resistors in a configuration like this.

<img src="../../images/week13/divider_01.jpg" alt="divider_01" width=100%/>

Formula:

<img src="https://cdn.sparkfun.com/assets/e/7/6/3/c/511968d9ce395f7c54000000.png" alt="divider_01" width=100%/>



### PWM

>Reference from [https://learn.sparkfun.com/tutorials/pulse-width-modulation/all](https://learn.sparkfun.com/tutorials/pulse-width-modulation/all)

PWM stands for Pulse-Width-Modulation and it's a way to process output signals to use it for digital control. It is used for processes like dimming for RGB LED control, and current/ voltage for speed motor control.

One important thing to know and remember its the "Duty Cycle", it depends in the percentage of time that a signal is High or LOW in a period of time.

For a 5 Volts circuit, if I use 0.1 seconds (10 Hz) for "Period of time" and the output is 5 Volts for every 0.05 seconds my duty cycle will be equal to 50%. If the output is High for 0.025 seconds the Duty Cycle will be 25%. And if its High for 0.06 seconds the Duty Cycle will be 60%.


### Sound and tones




### Pull-up resistors

A pull-up resistor is an circuit arrangement to solve *floating input* signals.

The Pin is connected to the Voltage source in this case 3.3 Volts. And it's used for the i2c SDA and SCL inputs. Without this pull resistors the i2c communication doesn't work.



### i2c protocol




### SAMD11E17 MUX table

| MUX | Serial | Pins |
| -- | -- | -- |
| Serial0 | N/A | N/A |
| Serial1 | PA14 | PA15 |


## Speaker

### Test

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/speaker_test_03.mp4" type="video/mp4">
	</video>
</figure>

### Circuit

<img src="../../images/week13/transistor_01.jpg" alt="transistor_01" width=100%/>

### Code

```
//This code produces a "beep" every one second.
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
  noTone(5);
}

```

### Demo

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/speaker_demo_03.mp4" type="video/mp4">
	</video>
</figure>

### Issues



## LCD Display

### Test

### Circuit

<img src="../../images/week13/pull_up_01.jpg" alt="transistor_01" width=100%/>


### Code
```
//This code uses:
// LiquidCrystal_I2C and Wire library.
// Pins 14 and 15 as SDA and SCL.
// This code makes the i2c display blink its backlight for 1 second and writes "hello" during setup and "world" during loop.
// Autor: Antonio de Jesus Anaya Hernandez
// Fab-Academy: 2021 Agrilab
// Country: France

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  Wire.begin();
  //setup lcd and write hello
  lcd.init();
}

void loop() {
  lcd.backlight();
  lcd.setCursor(1,2);
  lcd.print("world");
  delay(1000);
  lcd.noBacklight();
  delay(1000);
}
```

### Demo

### Issues



## Input + output

### Circuit

<img src="../../images/week12/demo_01.jpg" alt="demo_01.jpg" width=100%/>

### Code
```
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
```

### Demo

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/demo_01.mp4" type="video/mp4">
	</video>
</figure>

## Board

<img src="../../images/week13/pcb_01.jpg" alt="pcb_01" width=100%/>

### Issues

<img src="../../images/week12/board_02.jpg" alt="board_02.jpg" width=100%/>
