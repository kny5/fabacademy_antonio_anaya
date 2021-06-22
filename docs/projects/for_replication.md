# Final project: MILQ

<img src="../../presentation.png" alt="presentation" width=100%/>



## Description

MILQ its a device for checking the freshness of a milk sample. It reads FDX RFID animal earrings too, and uses a disposable espresso cup as sample collector.



## BOM

Tools:

| Tool | Specifications |
| -- | -- |
| Roland SRM-20 milling machine or alike | Sacrificial plate is needed for safety of the machine |
| Prusa i3 Mk2 3D printer machine or alike | Resolution needed to 0.10 mm for maximum dimensional accuracy with 0.4 mm nozzle. |
| Laser cutting machine | Effective working area more than 50 x 50 cms, power 150 Watts, CO2 and security protocol compliant trained operation, **Clean working space and Fire Extinguisher is mandatory** |
| Weller Pu-81 Soldering iron or alike | Precision tip for maximum accuracy, tool folder for comfort and security |


Supplies:

| Material | Quantity | Specifications |
| -- | -- | -- |
| Plexiglass | 75 x 15 cms or 40 x 30 cms | 6 mm thickness transparent or translucent |
| PLA Filament for 3D printer | > 10 grams | 1.75 diameter |
| FR1 Electronic board for milling | > 14 x 9 cms | 1.8 mm thickness, **flat**, single sided |
| 1.0 mm milling bit | Multiple | This tip is used for milling the FR1 electronic board, maximum quality the better for accurate trace milling |
| 0.4 mm milling bit | Multiple x2 | This tip is used for milling the FR1 electronic board, maximum quality the better for accurate trace milling, this component its extremely fragile |
| Double face tape | 1 roll | Stickiness should be enough to fix the FR1 to the sacrificial layer during the milling process |


Wires:

| Color | Quantity | Specifications |
| -- | -- | -- |
| Red | > 80 centimeter | Caliber AWG 24 |    
| Blue | > 80 centimeter | Caliber AWG 24 |    
| Optional 1 | > 30 centimeter | Caliber AWG 24 |
| Optional 2 | > 30 centimeter | Caliber AWG 24 |    
| 10 wires flat cable|  1.27 mm pitch JTAG connector |


Connectors:

| | Type | Quantity | Specifications |
| -- | -- | -- | -- |
| Dupont JST XH | | | [Link for purchasing](https://fr.aliexpress.com/item/1005001463771344.html) |
| | 2 Pins | 6 | male and female, plus connectors |
| | 3 Pins | 1 | male and female, plus connectors |
| | 4  Pins | 4 | male and female, plus connectors |
| Dupont Jumper Pin | | | [Link for purchasing](https://www.wish.com/product/5b655353560f5d7c2ecd9f07?from_ad=goog_shopping&_display_country_code=FR&_force_currency_code=EUR&pid=googleadwords_int&c=%7BcampaignId%7D&ad_cid=5b655353560f5d7c2ecd9f07&ad_cc=FR&ad_lang=FR&ad_curr=EUR&ad_price=6.00&campaign_id=8143443324&gclid=Cj0KCQjw5auGBhDEARIsAFyNm9E5gI7olP03C6wbNo97dyqIX1Gn-OZgUURI7Ub3fB6T09M_k1RAmaAaAkNvEALw_wcB&hide_login_modal=true&share=web) |
| | 4  Pins | 1 | female, plus connectors |
| JTAG self punching | | | |
| | 2x5 | 1 | female, 1.27 mm pitch |

Joinery:

| | Type | Quantity | Specifications |
| -- | -- | -- | -- |
| Nylon hexagonal spacers |
|



### Electronic components:

|Reference|Value                             |Footprint                                |Datasheet                                                                                      |
|---------|----------------------------------|-----------------------------------------|-----------------------------------------------------------------------------------------------|
|U5       |ATSAMD11C14A-SS                   |fabacademy2021:SOIC-14_3.9x8.7mm_P1.27mm |                                                                                               |
|R8       |10K                               |fabacademy2021:R_1206                    |~                                                                                              |
|C3       |1uF                               |fabacademy2021:C_1206                    |                                                                                               |
|J5       |Conn_01x04_Female                 |digikey:PinHeader_1x4_P2.54mm_Drill1.02mm|~                                                                                              |
|U1       |Regulator_Linear_LM3480-3.3V-100mA|fabacademy2021:fab-SOT23                 |https://www.ti.com/lit/ds/symlink/lm3480.pdf                                                   |
|R10      |10k                               |fabacademy2021:R_1206                    |~                                                                                              |
|R9       |10k                               |fabacademy2021:R_1206                    |~                                                                                              |
|C6       |0.1uF                             |fabacademy2021:C_1206                    |                                                                                               |
|J3       |Conn_01x04_Female                 |digikey:PinHeader_1x4_P2.54mm_Drill1.02mm|~                                                                                              |
|J4       |Conn_01x02                        |digikey:PinHeader_1x2_P2.54mm_Drill1.02mm|~                                                                                              |
|R3       |R                                 |fabacademy2021:R_1206                    |~                                                                                              |
|R4       |R                                 |fabacademy2021:R_1206                    |~                                                                                              |
|R5       |0                                 |fabacademy2021:R_1206                    |~                                                                                              |
|U3       |Regulator_Linear_NCP1117-5.0V-1A  |fabacademy2021:fab-SOT223                |https://www.onsemi.com/pub/Collateral/NCP1117-D.PDF                                            |
|C1       |C                                 |fabacademy2021:C_1206                    |~                                                                                              |
|J6       |Conn_01x02                        |digikey:PinHeader_1x2_P2.54mm_Drill1.02mm|~                                                                                              |
|J7       |Conn_01x02                        |digikey:PinHeader_1x2_P2.54mm_Drill1.02mm|~                                                                                              |
|Q1       |PN2222A                           |fabacademy2021:fab-SOT23                 |https://www.onsemi.com/pub/Collateral/PN2222-D.PDF                                             |
|C2       |1nF                               |fabacademy2021:C_1206                    |                                                                                               |
|R1       |1K                                |fabacademy2021:R_1206                    |~                                                                                              |
|R6       |100                               |fabacademy2021:R_1206                    |~                                                                                              |
|R13      |100                               |fabacademy2021:R_1206                    |~                                                                                              |
|R12      |1K                                |fabacademy2021:R_1206                    |~                                                                                              |
|C4       |1nF                               |fabacademy2021:C_1206                    |                                                                                               |
|Q2       |PN2222A                           |fabacademy2021:fab-SOT23                 |https://www.onsemi.com/pub/Collateral/PN2222-D.PDF                                             |
|J2       |Conn_01x02                        |digikey:PinHeader_1x2_P2.54mm_Drill1.02mm|~                                                                                              |
|J8       |Conn_ARM_JTAG_SWD_10              |fabacademy2021:fab-SWD10pin127pitch.lib  |http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf|
|R2       |R                                 |fabacademy2021:R_1206                    |~                                                                                              |



## Assembly process

<figure class="video_container">
	<video controls="true" allowfullscreen="true">
		<source src="../../presentation.mp4" type="video/mp4">
	</video>
</figure>
