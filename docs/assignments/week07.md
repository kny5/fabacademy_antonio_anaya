# 7. Electronics design

It might be a video for this week... depending on Monday's work.

<img src="../../images/week07/kicad_render_01.jpg" alt="Render_01" width=100%/>


<details closed>
<summary>A few notes for this week about documentation:</summary>
<p>

I've made a list of recommendations to get easily into the documentation process to help me out to have a structure, and with the hope to help others struggling under similar conditions.

<a href="../../Tips/documentation_tips/" > [Check my notes on my new Tips section.]</a>

</p>


</details>





## Electronic components:

**Resistor:**

*It's a passive electrical component that holds resistance to an electrical current.* [Detailed information](https://youtu.be/rcSOcbu6pDM?t=189)

| Component | Resistor |
| :----------- | :------------------- |
| Type | SMD 1206 |
| Value | 0 Ohms, 100 Ohms, 50 Ohms, 1 KOhms |
| Code | **Check** |
| Digikey #| 311-100FRCT-ND |
| Link | <a href="https://www.digikey.com/short/pd5fm4vp" target="_blank"> DigiKey </a> |

>Formula:

>Ohms Law: **Resistance = Voltage / Current**
Example for a 2V, 0.02A LED in a 5 Volts Power Supply: 5V - 2V = 3V; 3V / 0.02A = 150 Ohm



**Capacitor:**

*It's a passive electrical device used to store temporally a charge, consisting of one or more pairs of conductors separated by an insulator.*

| Component | Capacitor |
| :----------- | :------------------- |
| Type | SMD 1206 |
| Value | 1uF |
| Code | None |
| Digikey #| C3216X7R1H105K160AB |
| Link | <a href="https://www.digikey.com/short/fnhmzvj5" target="_blank"> DigiKey </a> |



**Regulator:**

*Any electrical or electronic device that maintains the voltage of a power source within acceptable limits.*

| Component | Regulator |
| :----------- | :------------------- |
| Type | SMD  SOT23 |
| Value | 3.3V 100mA |
| Code | None |
| Digikey #| LM3480IM3-3.3/NOPB |
| Link | <a href="https://www.digikey.com/short/5mntwv4z" target="_blank"> DigiKey </a> |



**Diode:**

*It's a semiconductor device with two terminals, typically allowing the flow of current in one direction only.*

| Component | light emitting diode (LED) |
| :----------- | :------------------- |
| Type | SMD 1206 |
| Value | 2V 0.02A |
| Code | None |
| Digikey #| 160-1167-1-ND |
| Link | <a href="https://www.digikey.com/short/8b9t5fjq" target="_blank"> DigiKey </a> |



**Micro-controller**

*It's a compressed micro computer manufactured to control the functions of embedded systems*

| Component | ATMEL SAMD11C14A Microcontroller |
| :----------- | :------------------- |
| Type | SMD 14 Pin |
| Value | 32Bits 48MHz 1.62~3.63V |
| Code | ATSAMD11C14A |
| Digikey #| ATSAMD11C14A-SSUTCT-ND  |
| Link | <a href="https://www.digikey.com/short/vv1nf30r" target="_blank"> DigiKey </a> |



## Electronic Schematics

**Symbols**

**Examples**

## Kicad

**Requirements**

1. Install [Kicad](https://kicad.org/about/kicad/){:target="_blank"}
2. Download or clone Fab Academy Kicad Library.
3. Add Symbol and Footprints libraries.
4. Add [Luc](https://fabacademy.org/2019/labs/sorbonne/students/hanneuse-luc/about/){:target="_blank"} and [Florent](http://fabacademy.org/2020/labs/agrilab/students/florent-lemaire/about/){:target="_blank"} USB and JTAG KiCad footprint files.
5. [SAMD11 datasheet.](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-42363-SAM-D11_Summary.pdf){:target="_blank"}
6. [SAMD11 pinout information.](https://github.com/mattairtech/ArduinoCore-samd/blob/master/variants/Generic_D11C14A/README.md){:target="_blank"}
7. Look for availability of components in your local inventory.


**Installation**

On Fedora Linux:
```
sudo dnf install kicad
```

Download for any other platform [here.](https://kicad.org/download/){:target="_blank"}

Cloning Fab Academy Kicad Library repository:
```
git clone https://gitlab.fabcloud.org/pub/libraries/electronics/kicad.git
```



### **Setup**


**Add Symbol library**

<img src="../../images/week07/kicad_02.jpg" alt="Managers" width=100%/>

>- Open Kicad, at the menu bar, click on: "Preferences">"Manage symbol libraries">"Global libraries".

<img src="../../images/week07/kicad_03.jpg" alt="Managers" width=100%/>

>- Click on: "Add a new empty row to table".

<img src="../../images/week07/kicad_04.jpg" alt="Managers" width=100%/>

>- Click on: "Library Path" and search-select the file **"fab.lib"** in Fab-Academy "kicad" repository.
>- Click on: "OK" and close the manager window.

**Add footprint library**

1. Click on: "Preferences">"Manage footprint libraries">"Global libraries".
2. Click on: "Add a new empty row to table".
3. Click on: "Library Path" and search-select the file **"fab.pretty"** in Fab-Academy "kicad" repository.
4. Click on: "OK" and close the manager window.

**Add custom USB and JTAG footprints**

1. Download this [file](../../files/week07/footprints.zip)
2. Extract the content to your Kicad project directory
3. Repeat the **Add Symbol library** and **Add footprint library** process using the files extracted.

**Edit footprints:**

**Make your own library:**



### Usage

**Symbol:**

<img src="../../images/week07/kicad_09.jpg" alt="Managers" width=100%/>

>- Click on: **"Place symbol"** icon, pulse left click on canvas.

<img src="../../images/week07/kicad_10.jpg" alt="Managers" width=100%/>

>- Select a component preferably from the **Fab Academy library**

**Global label:**

<img src="../../images/week07/kicad_07.jpg" alt="Managers" width=100%/>

>- Click on: **"Place global label"** icon, pulse left click on canvas.

<img src="../../images/week07/kicad_08.jpg" alt="Managers" width=100%/>

>- Write the a new name for a label or select an existing one from the drop-down menu.

**Wire:**

<img src="../../images/week07/kicad_05.jpg" alt="Managers" width=100%/>

>- Click on: **"Place wire"** icon, then left-click in the start and end points of the wire, you can connect symbols by clicking in their pin connection area, represented by a circle in the terminals.

**No connection:**

<img src="../../images/week07/kicad_06.jpg" alt="Managers" width=100%/>

>- Click on: **"Place no connection flag"**, left-click on every unused connection. This is important to avoid errors in the electrical check tool.

### Schematic layout design

>For this process I've selected the **hello.D11C.blink.reset.clock** board as the base of my design.

1. Divided the work in four parts:
    - Regulator
    - USB connector
    - JTAG conector
    - Microntroller
2. Placed the following list of symbols under the FabAcademy library:
    - ATSAMD11C14A
    - Regulator
    - USB connector
    - JTAG connector

<details closed>
<summary>USB connector</summary>

<img src="../../images/week07/workflow_01.jpg" alt="Managers" width=100%/>

<pre>

1. Wired the USB connector to the VCC and GNDREF symbols.
2. Placed Global labels:
    - VCC
    - GND
    - D+
    - D-
3. Wired the global labels to the USB connector:
    - VCC  to pin 1
    - D- to pin 2
    - D+ to pin 3
    - GND to pin 4

</pre>

</details>

<details closed>
<summary>Regulator</summary>

<img src="../../images/week07/workflow_02.jpg" alt="Managers" width=100%/>

<pre>

1. Placed the following symbols:
    - C1 capacitor 1uF
2. Placed global label:
    - VCC
    - GND
    - V3.3
    - btn_v33
3. Wired the sub-schema of the regulator.
    - VCC to pin 2
    - GND to pin 3
    - V3.3 to pin 1
    - pin 1 of C1 between GND and pin 3
    - pin 2 of C1 between pin 1 and V3.3
    - btn_v33 between pin 1 and V3.3

</pre>

</details>

<details closed>
<summary>JTAG connector</summary>

<img src="../../images/week07/workflow_03.jpg" alt="Managers" width=100%/>

<pre>



1. Placed Global labels:
    - V3.3
    - GND
    - CLK
    - DIO
    - RESET
2. Wired the sub-schema of the JTAG connector.
    - GND to pin 9 and pin 3
    - DIO to pin 2
    - CLK to pin 4
    - RESET to pin 10
    - VTref to V3.3


</pre>

</details>


<details closed>
<summary>Microcontroller</summary>

<img src="../../images/week07/workflow_04.jpg" alt="Managers" width=100%/>


<pre>


1. Placed the following components:
    - C2 actually this is a crystal and it took me a while after checking the images to discover it.
    - R1 100 Ohms
    - R4 100 Ohms
    - R5 10 KOhms
    - R6 10 KOhms
    - LED1
    - Button1
2. Placed the following global labels:
    - GND
    - RESET
    - V3.3
    - CLK
    - DIO
3. Wired the left-side of the Microntroller sub-schema:
    - GND to C2 to RESET and pin 6
    - V3.3 to R5 to point between C2 and RESET
    - V3.3 to R6 to pin 7
    - CLK to point between R6 and pin 7
4. Placed the following global labels:
    - VCC
    - GND
    - btn_v33
    - D+
    - D-
5. Wired the right-side of the Microntroller sub-schema:
    - GND to Button1 to pin 13
    - btn_v33 to point between Button1 and pin 13
    - VCC to anode of LED1
    - cathode of LED1 to R4
    - R4 to pin 1

</pre>

</details>


### Associate footprints

<img src="../../images/week07/workflow_06.jpg" alt="Managers" width=100%/>

>- Click on: **"Edit symbol fields"** icon in the toolbar.

<img src="../../images/week07/workflow_07.jpg" alt="Managers" width=100%/>

>- Associate every symbol to the right footprint in the Fab-Academy footprint library by clicking in every footprint cell and search-find the footprints in the fabacademy footprint library.

>- For the LED, Resistors, diode and Capacitor, select the *type 1206* footprint.
>- For the USB and JTAG connectors look into the custom library.



### Generate Netlist

<img src="../../images/week07/workflow_05.jpg" alt="Managers" width=100%/>

1. Click on: Icon "Generate Netlist" in the top toolbar
2. Click on: Button "Generate Netlist"
3. Save the **"".net"** file



### PCB Layout design

1. Open the PCB layout editor
2. Click on "Load netlist"
3.



### Troubleshooting




## Outcome




### Schematic

![schematic 1](../../images/week07/workflow_04.jpg)
![schematic 2](../../images/week07/outcome_sch_02.jpg)



### Footprints

![PCB footprints](../../images/week07/outcome_pcb.jpg)



### 3D model

![PCB 3D](../../images/week07/kicad_render_01.jpg)



### Processing files

### Milling

### Solder

### Debug

### Programming
