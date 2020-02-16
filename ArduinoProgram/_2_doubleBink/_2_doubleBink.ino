//init. & dec. t all here, to modify anything fom here;

//dec. pins
int orangeLedPin = 10;
int greenLedPin =  9;

//init. on\off time
int orangeOnTime = 100;
int orangeOffTime = 900;
int greenOnTime = 100;
int greenOffTime = 900;

//LEDs blinking number of times
int orangeNumber = 3;
int greenNumber = 3;

void setup() {
  //baud pace init. for serial printing
  //setup both pim as output 
  Serial.begin(115200);
  pinMode(orangeLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
}

void loop() {
  //blinking LEDs for specific numbers of time

  //orange led section
  for(int i = 1; i <= orangeNumber; i++)
  {
    //printing
    Serial.print("Green blinking:");
    Serial.println(i);

    //on/off -> time
    digitalWrite(orangeLedPin, HIGH); // on
    delay(orangeOnTime); // on time
    digitalWrite(orangeLedPin, LOW); //off
    delay(orangeOffTime); //off time
  }
  Serial.println(""); //print for separation
  
  //Green LED section
  Serial.println("Green LED blinking!");
  for(int i = 1; i <= greenNumber; i++)
  {
    digitalWrite(greenLedPin,HIGH); //on
    delay(greenOnTime); //ON TIME
    digitalWrite(greenLedPin, LOW); //off
    delay(greenOffTime); //OFF TIME
  }
}
