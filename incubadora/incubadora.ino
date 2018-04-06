//#include <Time.h>

#include <LiquidCrystal.h>

int LedPin = 9;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int sensorPin = A0;
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;
float valorApagado = 40;
float valorEncendido = 30;

void setup() {
  pinMode(LedPin, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  
  tiempo = millis();
  sensorValue = analogRead(sensorPin);
  volt = sensorValue*0.004889;
  temp = volt*100;

  while(temp < valorApagado){
    sensorValue = analogRead(sensorPin);
    volt = sensorValue*0.004889;
    temp = volt*100;
    digitalWrite(LedPin, LOW);
    maxi = max(maxi,temp);
    
    if(mini==0)
      mini = temp;
    else
      mini = min(mini,temp);
    
    if((tiempo/1000)%15 == 0){
      lcd.setCursor(0,1);
      lcd.print("MAX:");
      lcd.print(maxi);
      lcd.setCursor(0,0);
      lcd.print("MIN:");
      lcd.print(mini);
    }
  }
  while(temp > valorEncendido){
    sensorValue = analogRead(sensorPin);
    volt = sensorValue*0.004889;
    temp = volt*100;
    digitalWrite(LedPin, HIGH);
    maxi = max(maxi,temp);
    
    if(mini==0)
      mini = temp;
    else
      mini = min(mini,temp);
    
    if((tiempo/1000)%15 == 0){
      lcd.setCursor(0,1);
      lcd.print("MAX:");
      lcd.print(maxi);
      lcd.setCursor(0,0);
      lcd.print("MIN:");
      lcd.print(mini);
    }
  }
}

