// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
int LedPin = 8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//
int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0,tiempo = 0;
float volt,temp,maxi=0,mini=0;

void setup() {
  pinMode(LedPin, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print(".|. .|.");
  Serial.begin(9600);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  //digitalWrite(LedPin, HIGH);   // Enciende el pin 6
  //delay(500);                   // Espera medio segundo
  digitalWrite(LedPin, 1);   // Apaga el pin 6
  delay(500);
  
  tiempo = millis();
  sensorValue = analogRead(sensorPin);
  volt = sensorValue*0.004889;
  temp = volt*100;

  maxi = max(maxi,temp);
  if(mini==0)
    mini = temp;
  else
    mini = min(mini,temp);
    
  Serial.print("Medido: ");
  Serial.print(sensorValue);
  Serial.print("\t Voltaje: ");
  Serial.print(volt);
  Serial.print("\t Temperatura: ");
  Serial.print(temp);
  Serial.print("\t tiempo: ");
  Serial.println(tiempo/1000);
  Serial.println((tiempo/1000)%15);
  delay(1000);

  
  
  if((tiempo/1000)%15 == 0){
    Serial.print("MÁXIMO: ");
    Serial.print(maxi);
    lcd.print("MINIMO: ");
    lcd.print(mini);
  }
  
  //if (pulso = 1)
}

