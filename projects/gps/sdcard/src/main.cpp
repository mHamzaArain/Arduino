    /////////////////////////////////////////////////////////////////
   //              Arduino SD Card Tutorial     v1.00             //
  //       Get the latest version of the code here:              //
 //         http://educ8s.tv/arduino-sd-card-tutorial           //
/////////////////////////////////////////////////////////////////
#include <SD.h>
#include <SPI.h>

int CS_PIN = 10;

File file;

/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/////////////////////  SD Card  /////////////////////
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////

void initializeSD(){
  Serial.println("Initializing SD card...");
  pinMode(CS_PIN, OUTPUT);

  if (SD.begin())
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
    return;
  }
}

int writeToFile(char text[])
{
  if (file){
    file.println(text);
    Serial.println("Writing to file: ");
    Serial.println(text);
    return 1;
  } 
  else{
    Serial.println("Couldn't write to file");
    return 0;
  }
}

int openFile(char filename[]){
  file = SD.open(filename);
  if (file){
    Serial.println("File opened with success!");
    return 1;
  } 
  else{
    Serial.println("Error opening file...");
    return 0;
  }
}

void closeFile(){
  if (file){
    file.close();
    Serial.println("File closed");
  }
}

int createFile(char filename[]){
  file = SD.open(filename, FILE_WRITE);

  if (file){
    Serial.println("File created successfully.");
    return 1;
  } 
  else{
    Serial.println("Error while creating file.");
    return 0;
  }
}

////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////
////////////////////////////////////////////////////



void setup()
{
  Serial.begin(9600);

  initializeSD();
  delay(3000);
  createFile("test.txt");
  delay(3000);
  writeToFile("===READY===");
  delay(3000);
}

void loop()
{
  
  for (int i = 0; i <= 10; i++)
  {
    char str[10];
    sprintf(str, "%d", i);
    writeToFile(str);
    // str;
  }
  closeFile();
}

