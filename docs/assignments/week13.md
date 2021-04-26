# 13. Output Devices

## Introduction

This week I've started to use output devices that are part of my device for the final project.

- A **Speaker** to make a sound after a RFID successful read.
- A **LCD display** to show information relative to the milk production.

Then to make this possible I've listed here different components and concepts that were useful for me during this weeks work.



### 2N2222 Transistor

I've used the 2N2222 which is a multipurpose NPN transistor for low power amplification.

- For testing I've used the T0-92 form
- In my SMD circuit the SOT-23 form.

Datasheets:

- [P2N2222A](../../datasheets/P2N2222A.PDF)
- [MMBT2N2222A](../../datasheets/MMBT2N2222A.pdf)



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

<img src="../../images/week13/divider_01.jpg" alt="divider_01" width=100%/>



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

## Speaker for sound

### Test

### Circuit

### Code

### Demo

### Issues



## LCD Display

### Test

### Circuit

### Code

### Demo

### Issues



## SAMD21E17
