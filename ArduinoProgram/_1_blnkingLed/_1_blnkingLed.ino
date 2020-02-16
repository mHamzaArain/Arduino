int ledPin = 13;     //pin -> 13
int waitTimeOn = 500; // on 
int waitTimeOff = 250; //off

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH); //On
  delay(waitTimeOn); // On time
  
  digitalWrite(ledPin, LOW); //Off
  delay(waitTimeOff); //Off time
}
