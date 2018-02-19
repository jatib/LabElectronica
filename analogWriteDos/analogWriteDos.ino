int Salida = 11, Entrada = 12;
boolean entrada = LOW;
boolean led = LOW;

void setup() {
  pinMode(Entrada,INPUT);
  pinMode(Salida,OUTPUT);
}

void loop() { 
  entrada = digitalRead(12);

  if(entrada){
    led = !led;
  }
  digitalWrite(Salida,led);
  delay(100);
}

//LEER ATMEGA 328
