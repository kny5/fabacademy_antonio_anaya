# 11. Input devices

#Oscilloscope



## Board design

<img src="../../images/week11/schematic_01.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/schematic_02.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/schematic_03.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/schematic_04.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/pcb_01.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_02.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_03.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_04.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_05.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_06.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_07.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_08.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_09.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_10.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/pcb_11.jpg" alt="hero_01" width=100%/>

<img src="../../images/week11/inkscape_01.jpg" alt="hero_01" width=100%/>


<img src="../../images/week11/issue_01.jpg" alt="hero_01" width=100%/>
<img src="../../images/week11/issue_02.jpg" alt="hero_01" width=100%/>




## Hall effect fluid sensor

Code:

```
const int HALL = 4;
const long VIN_FACTOR = 3.3 / 1.023 ;
long value = 0;

void setup() {
  pinMode(HALL, INPUT);
  Serial.begin(9600);
}

void loop() {

value = analogRead(BTN);

Serial.println(value * VIN_FACTOR);

}

```

<img src="../../images/week11/arduino_01.jpg" alt="hero_01" width=100%/>





## Spectrometer sensor
In process

## RFID Reader

In process
