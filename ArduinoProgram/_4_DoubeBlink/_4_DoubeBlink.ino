int redLedPin = 9;
int onTime = 500;
int offTime = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redLedPin, HIGH); //on
  delay(onTime); //om time

  digitalWrite(redLedPin, LOW); /off
  delay(offTime); //off time 
}
