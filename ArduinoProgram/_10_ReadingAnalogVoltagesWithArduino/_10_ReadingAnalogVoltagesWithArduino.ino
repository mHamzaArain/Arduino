int potPen = A0; //assigning potPin analog pin address to A0
int readValue; //dec. readValue variable 
float voltage; //dec. voltage variablr

void setup() {
  pinMode(potPen, INPUT); //dec. potPen an input
  Serial.begin(9600); //Start your serail port
}

void loop() {
  readValue= analogRead(potPen); //read 'potPen' and your value is readValue
  //Serial.println(readValue); //print result to serial monitor
  voltage = (5.0/1023.0) * readValue;
  Serial.println(voltage);
  delay(250); //delay 250 milli sec.
}
