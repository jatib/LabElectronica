#include <SD.h>

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;
File myFile;

void setup()
{
  Serial.begin(9600);
  escribir(); 
}

void loop()
{
	// nothing happens after setup
}

int temperatura(){
  sensorValue = analogRead(sensorPin);
  volt = sensorValue*0.004889;
  temp = volt*100;
  
  return temp;
}

void escribir(){
  while (!Serial) {
   }


  Serial.print("Initializing SD card...");
   pinMode(10, OUTPUT);
   
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  myFile = SD.open("test.txt", FILE_WRITE);
  
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
	// close the file:
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}
