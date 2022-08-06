EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L fabacademy2021:Regulator_Linear_LM3480-3.3V-100mA U1
U 1 1 60435613
P 2150 1200
F 0 "U1" H 2150 1442 50  0000 C CNN
F 1 "Regulator_Linear_LM3480-3.3V-100mA" H 2150 1351 50  0000 C CNN
F 2 "fabacademy2021:SOT-23" H 2150 1425 50  0001 C CIN
F 3 "https://www.ti.com/lit/ds/symlink/lm3480.pdf" H 2150 1200 50  0001 C CNN
	1    2150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 5500 2100 5750
Wire Wire Line
	1950 5500 1950 5750
Text GLabel 1950 5750 3    50   Input ~ 0
D-
Text GLabel 2100 5750 3    50   Input ~ 0
D+
Connection ~ 2250 5500
Wire Wire Line
	2250 5650 2250 5500
Text GLabel 2250 5650 3    50   Input ~ 0
GND
Wire Wire Line
	2600 5500 2250 5500
$Comp
L power:GNDREF #PWR0101
U 1 1 6044F4CC
P 2600 5500
F 0 "#PWR0101" H 2600 5250 50  0001 C CNN
F 1 "GNDREF" H 2605 5327 50  0000 C CNN
F 2 "" H 2600 5500 50  0001 C CNN
F 3 "" H 2600 5500 50  0001 C CNN
	1    2600 5500
	1    0    0    -1  
$EndComp
Connection ~ 1800 5500
Wire Wire Line
	1800 5500 1550 5500
$Comp
L power:VCC #PWR0102
U 1 1 6044E432
P 1550 5500
F 0 "#PWR0102" H 1550 5350 50  0001 C CNN
F 1 "VCC" H 1565 5673 50  0000 C CNN
F 2 "" H 1550 5500 50  0001 C CNN
F 3 "" H 1550 5500 50  0001 C CNN
	1    1550 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 5500 1800 5650
Text GLabel 1800 5650 3    50   Input ~ 0
VCC
$Comp
L fabacademy2021:USB_A_PLUG J1
U 1 1 6043CF71
P 2000 4800
F 0 "J1" H 2378 4648 60  0000 L CNN
F 1 "USB_A_PLUG" H 2378 4542 60  0000 L CNN
F 2 "antonio_lib:fab-USB_A_male_plug" H 2378 4436 60  0000 L CNN
F 3 "" H 2000 4800 60  0000 C CNN
	1    2000 4800
	1    0    0    -1  
$EndComp
Text GLabel 1700 1200 0    50   Input ~ 0
VCC
Wire Wire Line
	1700 1200 1850 1200
Text GLabel 2750 1200 2    50   Input ~ 0
V3.3
$Comp
L fabacademy2021:C C1
U 1 1 6047DEC7
P 2500 1650
F 0 "C1" V 2248 1650 50  0000 C CNN
F 1 "1uF" V 2339 1650 50  0000 C CNN
F 2 "fabacademy2021:C_1206" H 2538 1500 50  0001 C CNN
F 3 "" H 2500 1650 50  0001 C CNN
	1    2500 1650
	0    1    1    0   
$EndComp
Text GLabel 2150 1750 3    50   Input ~ 0
GND
Wire Wire Line
	2150 1500 2150 1650
Wire Wire Line
	2350 1650 2150 1650
Connection ~ 2150 1650
Wire Wire Line
	2150 1650 2150 1750
Wire Wire Line
	2650 1650 2650 1200
Wire Wire Line
	2450 1200 2650 1200
Wire Wire Line
	2650 1200 2750 1200
Connection ~ 2650 1200
$Comp
L Connector:Conn_ARM_JTAG_SWD_10 J2
U 1 1 6053D0D1
P 4300 3100
F 0 "J2" H 3857 3146 50  0000 R CNN
F 1 "Conn_ARM_JTAG_SWD_10" H 3857 3055 50  0000 R CNN
F 2 "antonio_lib:fab-SWD10pin127pitch.lib" H 4300 3100 50  0001 C CNN
F 3 "http://infocenter.arm.com/help/topic/com.arm.doc.ddi0314h/DDI0314H_coresight_components_trm.pdf" V 3950 1850 50  0001 C CNN
	1    4300 3100
	1    0    0    -1  
$EndComp
Text GLabel 5050 3000 2    50   Input ~ 0
CLK
Wire Wire Line
	5050 3000 4800 3000
Text GLabel 5400 2800 2    50   Input ~ 0
RESET
Text GLabel 5050 3100 2    50   Input ~ 0
DIO
Wire Wire Line
	5050 3100 4800 3100
NoConn ~ 4800 3300
NoConn ~ 4800 3200
Text GLabel 4200 3950 3    50   Input ~ 0
GND
Wire Wire Line
	4200 3700 4200 3850
Wire Wire Line
	4300 3700 4300 3850
Wire Wire Line
	4300 3850 4200 3850
Connection ~ 4200 3850
Wire Wire Line
	4200 3850 4200 3950
Text GLabel 2650 900  2    50   Input ~ 0
btn_v33
Wire Wire Line
	2650 1200 2650 900 
$Comp
L fabacademy2021:R R7
U 1 1 60542741
P 5100 2800
F 0 "R7" V 4893 2800 50  0000 C CNN
F 1 "0 Ohms" V 4984 2800 50  0000 C CNN
F 2 "fabacademy2021:R_1206" V 5030 2800 50  0001 C CNN
F 3 "~" H 5100 2800 50  0001 C CNN
	1    5100 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	4800 2800 4950 2800
Wire Wire Line
	5250 2800 5400 2800
Wire Wire Line
	9600 2850 9600 2600
Text GLabel 9600 2600 1    50   Input ~ 0
btn_v33
NoConn ~ 9350 3650
NoConn ~ 9350 3450
Wire Wire Line
	10200 3350 10400 3350
Text GLabel 10500 3550 2    50   Input ~ 0
GND
Wire Wire Line
	9600 3350 9800 3350
Connection ~ 9600 3350
Wire Wire Line
	9600 3150 9600 3350
Wire Wire Line
	9350 3350 9600 3350
$Comp
L fabacademy2021:R R1
U 1 1 604C8DB9
P 9600 3000
F 0 "R1" V 9807 3000 50  0000 C CNN
F 1 "100 Ohms" V 9716 3000 50  0000 C CNN
F 2 "fabacademy2021:R_1206" V 9530 3000 50  0001 C CNN
F 3 "~" H 9600 3000 50  0001 C CNN
	1    9600 3000
	1    0    0    -1  
$EndComp
NoConn ~ 8350 3950
NoConn ~ 8350 3850
NoConn ~ 9350 3750
$Comp
L fabacademy2021:BUTTON_B3SN SW1
U 1 1 604AB35A
P 10000 3350
F 0 "SW1" H 10000 3635 50  0000 C CNN
F 1 "BUTTON_B3SN" H 10000 3544 50  0000 C CNN
F 2 "fabacademy2021:Button_Omron_B3SN_6x6mm" H 10000 3550 50  0001 C CNN
F 3 "https://omronfs.omron.com/en_US/ecb/products/pdf/en-b3sn.pdf" H 10000 3550 50  0001 C CNN
	1    10000 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 2500 4300 2350
Text GLabel 4300 2350 1    50   Input ~ 0
V3.3
Wire Wire Line
	8200 3650 8350 3650
Text GLabel 8200 3650 0    50   Input ~ 0
DIO
Wire Wire Line
	7800 3350 8350 3350
Connection ~ 7800 3350
Wire Wire Line
	7800 3200 7800 3350
Text GLabel 7800 3200 1    50   Input ~ 0
RESET
Wire Wire Line
	7900 3550 7750 3550
Connection ~ 7900 3550
Wire Wire Line
	7900 4050 7900 3550
Wire Wire Line
	7600 3950 7600 3850
Connection ~ 7600 3950
Wire Wire Line
	7750 3950 7600 3950
Wire Wire Line
	7750 3850 7750 3950
Wire Wire Line
	8350 3550 7900 3550
Wire Wire Line
	7600 4050 7600 3950
Connection ~ 7600 3350
Wire Wire Line
	7600 3350 7800 3350
Wire Wire Line
	7600 3350 7600 3550
Wire Wire Line
	7500 3350 7600 3350
Wire Wire Line
	7100 3350 7200 3350
$Comp
L fabacademy2021:C C2
U 1 1 60493CDD
P 7350 3350
F 0 "C2" V 7098 3350 50  0000 C CNN
F 1 "1 uF" V 7189 3350 50  0000 C CNN
F 2 "fabacademy2021:C_1206" H 7388 3200 50  0001 C CNN
F 3 "" H 7350 3350 50  0001 C CNN
	1    7350 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	9600 3850 9350 3850
Wire Wire Line
	9350 3950 9600 3950
Text GLabel 9600 3850 2    50   Input ~ 0
D-
Text GLabel 9600 3950 2    50   Input ~ 0
D+
Text GLabel 7900 4050 3    50   Input ~ 0
CLK
$Comp
L fabacademy2021:R R6
U 1 1 604AB00A
P 7750 3700
F 0 "R6" H 7820 3746 50  0000 L CNN
F 1 "10 KOhms" H 7820 3655 50  0000 L CNN
F 2 "fabacademy2021:R_1206" V 7680 3700 50  0001 C CNN
F 3 "~" H 7750 3700 50  0001 C CNN
	1    7750 3700
	1    0    0    -1  
$EndComp
Text GLabel 7600 4050 3    50   Input ~ 0
V3.3
Text GLabel 7100 3350 0    50   Input ~ 0
GND
$Comp
L fabacademy2021:R R5
U 1 1 60492D52
P 7600 3700
F 0 "R5" V 7393 3700 50  0000 C CNN
F 1 "10 KOhms" V 7484 3700 50  0000 C CNN
F 2 "fabacademy2021:R_1206" V 7530 3700 50  0001 C CNN
F 3 "~" H 7600 3700 50  0001 C CNN
	1    7600 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4450 8850 4350
Text GLabel 8850 4450 0    50   Input ~ 0
GND
Wire Wire Line
	8850 2650 8850 2950
Text GLabel 8850 2650 2    50   Input ~ 0
V3.3
$Comp
L fabacademy2021:ATSAMD11C14A-SS U2
U 1 1 6040E4D3
P 8850 3650
F 0 "U2" H 8850 4531 50  0000 C CNN
F 1 "ATSAMD11C14A-SS" H 8850 4440 50  0000 C CNN
F 2 "fabacademy2021:SOIC-14_3.9x8.7mm_P1.27mm" H 8850 2600 50  0001 C CNN
F 3 "" H 8850 2950 50  0001 C CNN
	1    8850 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 3550 10500 3550
$Comp
L Device:LED D1
U 1 1 604B111C
P 10200 3550
F 0 "D1" H 10193 3767 50  0000 C CNN
F 1 "LED" H 10193 3676 50  0000 C CNN
F 2 "fabacademy2021:LED_1206" H 10200 3550 50  0001 C CNN
F 3 "~" H 10200 3550 50  0001 C CNN
	1    10200 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9350 3550 9550 3550
Wire Wire Line
	9850 3550 10050 3550
$Comp
L fabacademy2021:R R4
U 1 1 6041205D
P 9700 3550
F 0 "R4" V 9907 3550 50  0000 C CNN
F 1 "100 Ohms" V 9816 3550 50  0000 C CNN
F 2 "fabacademy2021:R_1206" V 9630 3550 50  0001 C CNN
F 3 "~" H 9700 3550 50  0001 C CNN
	1    9700 3550
	0    -1   -1   0   
$EndComp
Text GLabel 10400 3350 2    50   Input ~ 0
GND
$EndSCHEMATC
