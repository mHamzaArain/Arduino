int potentioPin = A0;
int bluePin = 5;
int greenPin = 6;
int redPin = 7;

int readValue;
int writeValue;

void setup(){
  Serial.begin(9600);
  pinMode(potentioPin, INPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop(){
    readValue = analogRead(potentioPin);
    Serial.print("Potential Range: ");
    Serial.println(readValue);
    //writeValue = (255.0/1023.0) * readValue;
    Condition(readValue);    
}

void Condition(int readValue)
{
  if (readValue >= 0 || readValue < 300){
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  else if (readValue >= 300 || readValue < 600){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
  }
  else if (readValue >= 600 || readValue < 900){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
  }
  
  else{
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, HIGH);
  }
}
