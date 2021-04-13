const int BTN = 4;
const long VIN_FACTOR = 3.3 / 1.023 ;
long value = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
}

void loop() {

value = analogRead(BTN);

Serial.println(value * VIN_FACTOR);

}
