#include <SD.h>
#include <Time.h>
#include <TimeLib.h>

int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;
File myFile;

void setup()
{
  Serial.begin(9600);
  setTime(20,45,50,19,04,2018);
  while (!Serial) {
  }

  Serial.print("Initializing SD card...");
  pinMode(10, OUTPUT);

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done."); 
}

void loop()
{
  tiempo = millis();
  time_t t = now();

  if((tiempo%10000)==0){
    escribir(temperatura(),horaActual(t));
    leer();
  }
}

/**
*
* Definimos funcin hora
*
**/
String horaActual(time_t t){
  String value="",hora="",minuto="",segundo="";
  if(hour(t)<10){
    hora = hora+"0"+String(hour(t));
  }
  else{
    hora = hora+String(hour(t));
  }

  if(minute(t)<10){
    minuto = ":0"+String(minute(t));
  }
  else{
    minuto = ":"+String(minute(t));
  }
  if(second(t)<10){
    segundo = ":0"+String(second(t));
  }
  else{
    segundo = ":"+String(second(t));
  }
  
  return hora+minuto+segundo;
}


int temperatura(){
  sensorValue = analogRead(sensorPin);
  volt = sensorValue*0.004889;
  temp = volt*100;

  return temp;
}

void escribir(float a, String b){

  myFile = SD.open("test.txt", FILE_WRITE);

  if (myFile) {
    Serial.print("Writing to .txt...");
    myFile.print(a);
    myFile.print(" [C] a las");
    myFile.println(b);
    myFile.close();
    Serial.println("done.");
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void leer(){

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
  } 
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

