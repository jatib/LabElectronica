#include <Time.h>
#include <TimeLib.h>
#include <LiquidCrystal.h>
//SERIAL READ 
int LedPin = 9;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorPin = A0;
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;
float valorApagado = 40;
float valorEncendido = 30;
String value="",hora="",minuto="",segundo="";
int minutos=0,horas=0,segundos=0,incomingByte=0; 

void setup() {
  pinMode(LedPin, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  setTime(23,59,50,20,03,2018);
}

void loop() {

  time_t t = now();

  lcd.setCursor(0,0);
  lcd.print("HORA ACTUAL");

  // send data only when you receive data:
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.print("Set hours: ");
    value = value + char(incomingByte);
    if(value.length() >= 2 ){
      hora = value;
      value = "";
      Serial.println(hora);
      incomingByte = Serial.read();
      Serial.print("Set minutes: ");
      value = value + char(incomingByte);
      if(value.length() >= 2 ){
        minuto = value;
        value = "";
        Serial.println(minuto);
        incomingByte = Serial.read();
        Serial.print("Set seconds: ");
        value = value + char(incomingByte);
      }
    }
  }

  lcd.setCursor(0,1);

  if(hour(t)<10){
    lcd.print("0");
    lcd.print(hour(t));

  }
  else{
    lcd.print(hour(t));
  }

  if(minute(t)<10){
    lcd.print(":0");
    lcd.print(minute(t));
  }
  else{
    lcd.print(":");
    lcd.print(minute(t));
  }
  if(second(t)<10){
    lcd.print(":0");
    lcd.print(second(t));
  }
  else{
    lcd.print(":");
    lcd.print(second(t));
  }
  delay(1000);  
}



