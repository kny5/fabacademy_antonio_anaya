const int BTN = 2;
int BTN_STATE = digitalRead(BTN);
const long VIN_FACTOR = 3.3 / 1.023 ;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(9600);
}

void loop() {

Serial.println(analogRead(BTN) * VIN_FACTOR);

analogWrite(LED_BUILTIN, analogRead(BTN) );
}
