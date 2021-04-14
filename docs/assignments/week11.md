# 11. Input devices

<img src="../../images/week11/hero_00.jpg" alt="hero_01" width=100%/>



## Introduction

This week I've learn to include a sensor on a pcb design, to programming it and to use the input data.

I've chose to use use this input devices:

1. A3144 Hall effect sensor.
2. RFID ISO11784 for animal Tag FDX reading board
3. Sparkfun's AS726x Spectral sensor VISIBLE

[Group assignment](http://fabacademy.org/2021/labs/agrilab/group/week11/)



## Testing sensors with SAMD11 board

I've used my SAMD11 board from [week07](../../assignments/week07), I've soldered wires to the pins to access the io pins.

<img src="../../images/week11/test_01.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/test_02.jpg" alt="hero_01" width=100%/>



## Oscilloscope

While working on the breadboard inspecting the pinouts I've had the idea to make analog write, place a wire as probe in the middle of an Oscilloscope.

I've observed a change in the wave when tested the probe into my chocolate "cocoa" beverage.


<figure class="video_container">
  <video controls="true" allowfullscreen="true" poster="path/to/poster_image.png" width=100% loop>
    <source src="../../images/week11/demo_02.mp4" type="video/mp4">
  </video>
</figure>

<img src="../../images/week11/test_03.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/test_05.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/osc_04.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/ds_00.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/ds_01.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/ds_02.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/osc_02.jpg" alt="hero_01" width=100%/>

The change it's really small but gives me the idea that connecting an amplifier I'll be able to get a better signal processing.

This is of my interest for my final project, for QC of milk based in EC.

After this exercise I've jump to design a new board.



## Board design

### Micro-controller and connector arrangement

I've used the SAMD11 micro-controller, but I've got the understanding that I've like to use more peripherals I should switch to the SAM21 which has more IO and memory.



### Components

Final design:

1. Reset button
2. Input button
3. Output LED
4. 2 Connectors 1x04
5. 1 Connector 1x05
6. Hall effect sensor and voltage divider

Discarded:

1. JTAG connector
2. Micro-USB female connector


**Micro-controller and connector arrangement**

<img src="../../images/week11/schematic_01.jpg" alt="hero_01" width=100%/>

**Clock, LED and input button arrangement**

<img src="../../images/week11/schematic_02.jpg" alt="hero_01" width=100%/>

**Reset button and regulator arrangement**

<img src="../../images/week11/schematic_03.jpg" alt="hero_01" width=100%/>

**USB connector and HALL effect sensor arrangement**

<img src="../../images/week11/schematic_04.jpg" alt="hero_01" width=100%/>

**After my instructors advice I've flipped my schematics following the positive-top, ground-bottom convention.**

<img src="../../images/week11/schematic_05.jpg" alt="hero_01" width=100%/>



### PCB design

I've faced some problems while designing my board.

- I didn't use an 0.4mm clearance
- I've used an USB connector that's not possible to mill with a 0.4mm milling bit.
- I've started the tracing from outside to the inside and later I've problems with the connector's tracks., so I had to start over and design from the inside to the outside.

This was my first approach before noticing this problems.

<img src="../../images/week11/pcb_01.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_02.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_03.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_04.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_05.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_06.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_07.jpg" alt="hero_01" width=100%/>

**Changing to inside to outside strategy**

<img src="../../images/week11/pcb_09.jpg" alt="hero_01" width=100%/>

I've worked also with my schematic in one side to add jumpers and check the sequence of connections properly to avoid shorcuts and misplaced components

<img src="../../images/week11/pcb_10.jpg" alt="hero_01" width=100%/>

I've used inkscape to make and outline with this shape. The funny round thing in the right it's just my approach to make a rotation sensor board with the hall effect sensor. Wo the axis of the rotor is going to pass through the 10 mm hole.

<img src="../../images/week11/inkscape_01.jpg" alt="hero_01" width=100%/>

Then I've imported the design into Kicad as SVG.

<img src="../../images/week11/pcb_11.jpg" alt="hero_01" width=100%/>

Then I've realized the problems with the traces for milling... and I had to rework my traces again.

<img src="../../images/week11/issue_01.jpg" alt="hero_01" width=100%/>

This is the final PCB design

<img src="../../images/week11/pcb_12.jpg" alt="hero_01" width=100%/>



### Milling

For milling I've made three files using mods.

1. Tracks
2. Holes
3. Outline

<img src="../../images/week11/milling_03.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/milling_05.jpg" alt="hero_01" width=100%/>



## Hall effect fluid sensor

Stuffing:

<img src="../../images/week11/stuffing_01.jpg" alt="hero_01" width=100%/>

Soldering order:

1. Micro-controller
2. Jumpers
3. Oscillators
4. Resistors
5. Buttons
6. Connectors
7. Hall effect SMD

<img src="../../images/week11/hero_00.jpg" alt="hero_01" width=100%/>



### Code

```
/*
This program reads the analog output of a HALL effect A-1324 sensor to millivolts

Pinout:

HAll sensor @ PIN 4

Pseudo-code:

First declares the constants "HALL" to 4, "VIN_FACTOR" the factor of conversion to analog to millivolts 3.3/1023.

Declares a long precision variable "value".

Sets Hall pin as input, and starts Serial (USB) communication at 9600 bauds.

Loops analog read of HALL and sends TX Serial with the result of Value times VIN_FACTOR.

Autor: Antonio de Jesus Anaya Hernandez
Agrilab, France.
Fabacademy week 11.

*/

const int HALL = 4;
const long VIN_FACTOR = 3.3 / 1.023 ;
long value = 0;

void setup() {
  pinMode(HALL, INPUT);
  Serial.begin(9600);
}

void loop() {

value = analogRead(HALL);

Serial.println(value * VIN_FACTOR);

}

```

Using Arduino's serial plotter I've found the sensor sends a lot of noise, and I've learn that's normal because of the materials of the board.

<img src="../../images/week11/arduino_01.jpg" alt="hero_01" width=100%/>

This is the signal response when an magnet passes 3 times over the sensor at 3mm distance.  

<img src="../../images/week11/step_01.jpg" alt="hero_01" width=100%/>

The the step is very small around 100 mV, the hall sensor needs at least 4.5V so I've think that maybe the voltage divider is not a good idea after all. So in the future I'll like to switch to a regulator, and test again.



## RFID Reader

### About RFID:

RFID stands for "radio-frequency identification" and belongs to AIDC technologies, "Automated identification and data capture".

This is an important part of my final project and RFID it's board used in animal identification systems.

<img src="../../images/week03/postit.jpg" alt="hero_01" width=100%/>

Here I'm using an FDX stadard reader that's used also in Mexico for cattle identification.

Every cow in France gets an RFID earring by default but in Mexico its deployment its still ongoing due to multiple factors like supply chain and distribution.

<img src="../../images/week03/photo_1.jpg" alt="hero_01" width=100%/>

```
/*
This program reads the TX output of the RFID ISO11784 for animal Tag FDX reading board, using the Serial1 interface of the SAMD11 micro-controller.

TX to RX on pin 31 Serial1


Autor: Antonio de Jesus Anaya Hernandez
Agrilab, France.
Fabacademy week 11.
*/

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  char id = Serial1.read();
  Serial.println(id);
  delay(100);
}
```



### Flashing

<script id="asciicast-9uphJuuU7P0OiTTZe8sKLbwrr" src="https://asciinema.org/a/9uphJuuU7P0OiTTZe8sKLbwrr.js" async></script>



### Serial output

<script id="asciicast-wSqG449cNzomrx4QNRKXbDJVJ" src="https://asciinema.org/a/wSqG449cNzomrx4QNRKXbDJVJ.js" async></script>



### Video

<figure class="video_container">
  <video controls="true" allowfullscreen="true" poster="path/to/poster_image.png" width=100% loop>
    <source src="../../images/week11/demo_01.mp4" type="video/mp4">
  </video>
</figure>



## Sparkfun spectral sensor

I've been stuck on this due to the library size. I've above 7000 bytes of the flash memory.

So I've been looking to the [AS7262 datasheet](https://cdn.sparkfun.com/assets/parts/1/2/2/4/9/AS7262_Datasheet.pdf#G1006885)


So I've learn that its possible to use i2c protocol by writing bytes to the sensor or UART by sending commands.

To read the device temperature:
- i2c: 0x06 bit 7:0
- UART: ATTEMP

Things I've to do to enable UART communication:

- Remove the solder from the Jp1 jumper
- Add a older to the jp2 jumper.

<img src="../../images/week11/sparkfun_01.jpg" alt="hero_01" width=80%/>
<img src="../../images/week11/sparkfun_02.jpg" alt="hero_01" width=40%/>
<img src="../../images/week11/sparkfun_03.jpg" alt="hero_01" width=40%/>


## Files
