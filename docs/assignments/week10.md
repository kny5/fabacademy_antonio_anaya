# 10. Mechanical design / Machine design

<img src="../../images/week10/hero_01.jpeg" alt="hero_01" width=100%/>



## Introduction

On this week we learn to design and make a machine. We faced different difficulties related to the teamwork, machine motion, electronics and the GCODE.



## Idea

We first talked together to explain our ideas and split the work.

- [Theo's](link) idea: Pancake machine.
- [Elina's](link) idea: 3 axis CNC machine.
- My idea was to stick to someone's else idea. So we agreed to work together to develop Theo's pancake machine.

This was the first sketch we made together.

<img src="../../images/week10/sketch_01.jpeg" alt="sketch_01" width=100%/>

Then we explored the available materials and parts in the Lab.



### Work split

1. Theo machine design and building
2. Antonio CNC control system
3. Elina pumping system and pancake recipe



### Criteria to chose the materials for the structure

1. Food safety
2. Structural strength  
2. Heat resistance
2. Quantity
3. Quickness for building



### Materials selected

1. Plexiglass
2. MDF wood 6mm thickness
3. Extruded aluminum profile



## Requirements

### Parts

<img src="../../images/week10/parts_01.jpeg" alt="parts_01" width=100%/>

**Click on name to check reference in Digikey**

| Part | Quantity |
| --- | --- |
| NEMA 17 step motors  | 2 |
| CNC GRBL arduino UNO compatible board | 1 |
| HR4988 Motor drivers | 2 |
| Limit switches | 2 |  
| Arduino UNO | 1 |
| Connectors for wiring | # |
| Recycled ATX power supply | 1 |



### Consumables

<img src="../../images/week10/consumables_01.jpeg" alt="consumables_01" width=100%/>

1. Ribbon wire 4 colors for stepper motors
2. AWG wire 1669
3. Connectors "Type 1"
4. Connector "Type 2"



### Tools

<img src="../../images/week10/tools_01.jpeg" alt="tools_01" width=100%/>

1. Crimping D Sub-terminal
2. Soldering iron
3. Clippers
4. Multimeter
5. Cross screw driver
6. Wire stripper



### Software

1. [Arduino IDE](https://www.arduino.cc/en/software)
2. [Universal Gcode sender](https://winder.github.io/ugs_website/download/)
3. [GRBL firmware](https://github.com/grbl/grbl)
4. [Fusion 360](https://www.autodesk.com/products/fusion-360/overview)

**Instructions for the usage and configurations are detailed in the next steps.**



## Using an ATX Power supply

<img src="../../images/week10/atx_01.jpeg" alt="atx_01" width=100%/>

We checked possible power sources and the most suitable one was this recycled ATX power supply.

In AgriLab there's a large stock of recycled parts and materials.



### Power on jumper

To switch on the power supply I added a jumper between the green wire and ground.

1. Cut the wires
2. Connect using an electrical union connector

<img src="../../images/week10/atx_02.jpeg" alt="atx_02" width=45%/>

<img src="../../images/week10/atx_03.jpeg" alt="atx_03" width=45%/>



### Outputs

This is the table with the Voltage and Power of every output in the ATX power supply.

<img src="../../images/week10/atx_04.jpeg" alt="atx_04" width=100%/>

I've used 3 pairs of 12 Volts based in the power consumption of every component listed here:

| Part | Voltage | Wire color | Black Ground wire |
| -- | -- | --- | --- |
| Arduino UNO board | 5 Volts | Red | Yes |
| GRBL board | 12 Volts | Yellow | Yes |
| 12 V Red LED | 12 Volts | Yellow | Yes |
| Peristaltic pump | 12 Volts | Yellow | Yes |



## CNC control system assembly and configuration

Introduction:

The GRBL board we have it's a common one used for CNC machines, like small low power laser cutters, small milling machines and vinyl cutters.



### CNC board

This is the schematic given by the manufacturer.

<img src="../../images/week10/schematic_01.jpeg" alt="schematic_01" width=100%/>

characteristics:

| GRBL | Board | |
| -- | -- | -- |
| Operation voltage | 12 to 16 V | not regulated, only protected by a fusible |
| Axis | 3 connectors for XYZ | +1 Clone axis connector |
| Limit switches | +-X, +-Y, +- Z | |
| Spindle control | Enable, Direction, cooling | Also used for laser output control |
| Machine override controls | Abort, Hold, Resume | |
| Emergency stop | | |
| Serial communication pinouts | SDA, SCL, TX RX, RST, 3.3V 5V | |
| Microstepping configuration jumpers | 1/2, 1/4, 1/8, 1/16 | |



### Assembly

Connect the motor driver boards to the GRBL board sockets. Check the pinout and be sure all the pins coincide correctly.

<img src="../../images/week10/cnc_01.jpeg" alt="cnc_01" width=100%/>



### Motor drivers

Characteristic:

| HR4988 motor driver | | |
| --- | --- | --- |
| Operation voltage | 5 Volts |  |
| Resistance | R100 | 0.1 Ohms |
| Motor Voltage Regulator | Potentiometer for VREF |

Pinouts in order:

| Left | Right |
| --- | -- |
| Direction | GND |
| Step | VDD |
| Sleep | 1B |
| Reset | 1A |
| MS3 | 2A |
| MS2 | 2B |
| MS1 | GND |
| Enable | VMOT |



### Stepper motors

#### Wiring

The wiring with the stepper motors was confusing and I invested one afternoon to find out the right wiring configuration.

Following the color code the wires should be punched in the connector like this:

| Motor driver | Step motor |
| -- | -- |
| Green | Red |
| Red | Blue |
| Black | Green |
| Blue | Black |



#### VREF calibration

This is an important task to prevent over-heating of the motor drivers, and excessive vibration and over-heating of the step motors.  

[This the motor datasheet provided by the manufacturer](link)
[SMD resistor calculator](http://kiloohm.info/smd4-resistor/R100)

Calculation:

| Values | | |
| -- | -- | -- |
| Current Sense resistance | 0.01 Ohms | Rsense |
| Rated motor current | 1.3 A | RMC |
| Safety margin percentage | 25 % | SM |

I've found this formula VREF = RMC x 8 x Rsense

<img src="../../images/week10/vref_01.jpeg" alt="vref_01" width=100%/>

Process:

1. Use the multimeter as voltmeter in a scale of less than 5 Volts.
1. Get a multimeter with a clamp connector in the cathode
2. Power on the GRBL board
3. Place the cathode (screw driver) in the VREF potentiometer and the ground probe in the bottom left GND pin.
4. Turn the potentiometer clockwise to increase and anti-clockwise to decrease the VREF.



#### Steps per millimeter for belt driven systems

I've calculated this using this [calulator.](https://zalophusdokdo.github.io/StepperMotorsCalculator/en/index.html)

| Data | Value |
| -- | -- |
| Motor step angle | 1.8° |
| Driven Microstepping | Full step |
| Belt pitch | 2 mm (GT2) |
| Pulley tooth count | 20 |

**Result: 5.00**

| Resolution | Teeth | Step angle | Stepping | Belt |
| -- | -- | -- | -- | -- |
| 200 micron | 20 | 1.8° | Full step | 2mm |


### GRBL

[GRBL](https://github.com/grbl/grbl) is an Open-Source firmware that runs in Atmega328 based Arduinos for low cost CNC machines. The version I've used is the v1.1 released in 08/2019.

I've dowloaded the repository:

```
git clone https://github.com/grbl/grbl.git
```

Install requisites for Fedora Linux:

- Avr gcc compiler
- Arduino

```
sudo dnf install avr-gcc arduino
```



#### Upload with Arduino

#### Disable Z axis homing routine

#### Firmware configuration

### Valid GCODE

## Wiring and connections

## Fusion 360 work-flow

### Design

### Manufacturing

### NC file post-processing

## Fine tuning

## Universal GCODE sender

### Configurations

## Troubleshooting

## Files
