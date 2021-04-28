# 13. Output Devices

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/demo_01.mp4" type="video/mp4">
	</video>
</figure>

## Introduction

This week I've started to use output devices that are part of my device for the final project.

For this week I've used my board from [week11, input devices based on the ATSAMD11 micro-controller.](../../assignments/week09)


<img src="../../images/week11/hero_00.jpg" alt="hero_01" width=100%/>


- A **Speaker** to make a sound after a RFID successful read.
- A **LCD display** to show information relative to the milk production.

Then to make this possible I've listed here different components and concepts that were useful for me during this week work.

Possible thing to use for this week work:

- Relay
- Speaker

<img src="../../images/week13/outputs_02.jpg" alt="outputs_02.jpg" width=100%/>

- LCD i2c display
- TFT display
- OLED i2c display

<img src="../../images/week13/outputs_01.jpg" alt="outputs_01.jpg" width=100%/>

Also I've contributed to this weeks [Group assignment](http://fabacademy.org/2021/labs/agrilab/group/week13/) by checking the power consumption of a display and a speaker.



### 2N2222 Transistor

I've used the 2N2222 which is a multipurpose NPN transistor for low power amplification.

- For testing I've used the T0-92 form
- In my SMD circuit the SOT-23 form.

Datasheets:

- [P2N2222A](../../datasheets/P2N2222A.PDF)
- [MMBT2N2222A](../../datasheets/MMBT2N2222A.pdf)

<img src="../../images/week13/IMG_20210422_171541.jpg" alt="IMG_20210422_171541.jpg" width=100%/>

I've used this on my speaker circuit for amplification.



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

The tone() function in the arduino library generates a square wave of the specified frequency (and 50% duty cycle) on a pin. A duration can be specified, otherwise the wave continues until a call to noTone(). The pin can be connected to a piezo buzzer or other speaker to play tones.

Only one tone can be generated at a time. If a tone is already playing on a different pin, the call to tone() will have no effect. If the tone is playing on the same pin, the call will set its frequency.

I've used this to produce a note C8 with the speaker. See the value 4186 in the tone() function.


### Pull-up resistors

A pull-up resistor is an circuit arrangement to solve *floating input* signals.

The Pin is connected to the Voltage source in this case 3.3 Volts. And it's used for the i2c SDA and SCL inputs. Without this pull resistors the i2c communication doesn't work.



### i2c protocol

i2c is a protocol that improves features from UART and SPI, its useful is you want to connect multiple devices using only 2 wires. An important remark is that every device that uses i2c has an hexadecimal "address" in this case I'm using **0x27** and I've find this in the LCD i2c documentation.



### SAMD11 MUX table

Under the Arduino IDE we can select the number and types of com protocols to be used in our program and bootloader. To understand this more in detail I had to check the MUX table in the [ATSAMD11 documentation](http://ww1.microchip.com/downloads/en/devicedoc/atmel-42363-sam-d11_datasheet.pdf).

<img src="../../images/week13/uart_01.jpg" alt="tran_01" width=100%/>

<img src="../../images/week13/mux_01.jpg" alt="transistor_01" width=100%/>

<img src="../../images/week13/mux_02.jpg" alt="transistor_01" width=100%/>


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



## LCD Display

### Circuit

I'm using here pull-up resistors

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
  lcd.setCursor(1,1);
  lcd.print("Hello");
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

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/display_02.mp4" type="video/mp4">
	</video>
</figure>



## Input + output

| Parts list | | |
| -- | -- | -- |
| Resistor | 1 | 1K |
| Resistor | 1 | 2K |
| 2N2222 | 1 | SOT-32 |
| 1x04 connector | 2 |
| 1x03 connector  | 1 |

[RFID WL-134KHz Datasheet](https://allinbest.com/blog/1342k-animal-tag-fdxb-iso11784-reader-module/)


### Circuit

<img src="../../images/week13/demo_01.jpg" alt="demo_01.jpg" width=100%/>



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

This is the messy setup of my input+output first attempt. I integrates this elements:

- Speaker
- RFID 134KHz
- LCD Display

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../images/week13/demo_01.mp4" type="video/mp4">
	</video>
</figure>



## Board

I've made this board to replace the wiring of my circuit, although during the weekend I've broke one of the 1x04 connectors.

<img src="../../images/week13/pcb_01.jpg" alt="pcb_01" width=100%/>



### Issues

<img src="../../images/week13/board_02.jpg" alt="board_02.jpg" width=100%/>

I'll change the design of my board on the:

- Connectors
- Transistor type



## Files

Code:

- [Speaker code](../../files/week13/speaker.ino)
- [Display code](../../files/week13/display.ino)
- [RFID, Speaker and Display code](../../files/week13/speaker_lcd_rfid.ino)

Circuits:

- [Kicad project file](../../files/week13/kicad/wee13.pro)
- [Schematic](../../files/week13/kicad/wee13.sch)
- [PCB](../../files/week13/kicad/wee13.kicad_pcb)
- [Netfile](../../files/week13/kicad/wee13.net)

Milling Roland SRM-20:

- [Traces](../../files/week13/roland_srm20/week13_audio_rfid.rml)
- [Outline](../../files/week13/roland_srm20/week13_outline.rml)
