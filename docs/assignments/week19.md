# 19. Project development.

## Introduction:

My final project development will consist in the design and manufacture of a device inspired on this form factor:


[Milk Checker](https://www.arbrown.com/english/products/milk_test/digital_mastitis_detector/)

![](../../images/week17/ref_02.jpg)
<!--[](../../images/week17/ref_02_a.jpg)-->
[Datasheet](https://www.arbrown.com/english/products/milk_test/digital_mastitis_detector/dl3.html)

Concepts of form factor and electronics:

<img src="../../images/week19/concept_01.jpg" alt="concept_01" width=100%/>
<img src="../../images/week19/concept_02.jpg" alt="concept_02" width=100%/>



## What tasks have been completed, and what tasks remain?

Due to a short of time caused by health issues I've decided to cut tasks and focus in the simplest functions of the project:

Completed tasks:

- Identify cow in production using RFID.
- Display information of current process.

Remaining tasks:

- Measure the quantity of milk produced by identified cow.
- Estimate the Quality of milk based in its content of Fat/Protein.
- Save the data generated per cow.
- Send data over USB, serial communication.

New tasks added:

- Identify fresh and 5 days not refrigerated milk.




## What has worked? what hasn't?

The DAC output of my final project has worked but with a Frequency limited to 1 KHz, to increase the frequency of the signal generated I've worked on a Multivibrator circuit. To generate an AC signal up to 1 MHz frequency.




## What questions need to be resolved?

The correlation between dielectric spectroscopy and the quality of milk based in the proportion of Fat and Protein needs to be approached in detail and with access to a production facility.



## What will happen when?

| week01 to week16 | week17 | week18 | week19 | week20 |
| -- | -- | -- | -- | -- |
| General and user research |
| | Proposals, Hardware, Software, Interaction |
| | | Second prototype, Workbench test. |
| | | | First prototype, workbench test, feedback and rework |
| | | | | Video demo |



## what have you learned?

During the last four weeks I've experimented with different things for my final project especially for the electronics here I summarize the most important things I've learned.

### Electronic circuits design in details

During the weeks I've learned how to produce electronics in different shapes by importing contour files in DXF format in Kicad.

Button board with LEDs:

<img src="../../images/week19/electronics_01.jpg" alt="electronics_01" width=100%/>

Immersive electrode for the transmission of Alternate Current signals:

<img src="../../images/week19/electronics_02.jpg" alt="electronics_02" width=100%/>

SAMD11C14 based board for DAC 1 Khz and Analog to Digital capturing:

<img src="../../images/week19/electronics_03.jpg" alt="electronics_03" width=100%/>

Usage of connectors for clean wiring of electronics:

<img src="../../images/week19/prototype_01.jpg" alt="prototyping_01" width=100%/>

I've made a USB cable connector using a 4 pin connector instead of the USB milled connector used during the weeks on my designs.

<img src="../../images/week19/prototype_02.jpg" alt="prototyping_02" width=100%/>



### Packaging

I've made several iterations in the packaging development the common failures were caused by:

- Kerf.
- Brittleness of materials.
- Mechanical assembly of laser cut pieces.

<img src="../../images/week19/packaging_02.jpg" alt="packaging_02" width=100%/>

This first prototype was impossible to assembly without breaking the pieces due to its tighten assembly connections.

<img src="../../images/week19/packaging_01.jpg" alt="packaging_01" width=100%/>



### Prototyping and iteration

Prototyping takes time, its the most obvious thing but it can be hard to make it on time without considering every component.

For that I've reasoned in the next following steps for a successful project integration:

- Initial form factor design
- User interaction considerations
- Inputs and outputs
- Electronics design
- Power supply selection
- Location of components inside and outside the package
- Wiring
- Packaging design
- Joining mechanisms

This reassembles the [FabAcademy program](https://fabacademy.org) and now I've a better understanding about the order of the assignments we have been following during this weeks.



### DAC Signal generation with SAMD11C14 microcontroller.

I've learned to generated signals using the [MPLAB IDE of Microchip](https://microchip-mplab-harmony.github.io/csp_apps_sam_d11/apps/dac/dac_wav_gen/readme.html) with the Harmony library.

This is the result observed in the oscilloscope.

<img src="../../images/week19/signal_01.jpg" alt="context_01" width=100%/>
