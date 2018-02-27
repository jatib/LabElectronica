int Salida = 9, Entrada = 8;
boolean entrada = LOW;
boolean led = LOW;
int inicio = 0, medio = 0, fin = 0, wait = 0, contador = 0;

void setup() {
  pinMode(Entrada,INPUT);
  pinMode(Salida,OUTPUT);
   Serial.begin(9600);
}

void loop() { 
  entrada = digitalRead(Entrada);

  while(entrada == 1){
    //ESTE EL DE ENTRADA
    if(contador == 1){
        
        Serial.print("Tiempo de espera entre clics:");
        Serial.println(inicio-wait);
        contador = 0;
      }
    medio = millis();
    fin = medio - inicio;
    entrada = digitalRead(Entrada);
     //ESTE ES EL IF DE ESCAPE
    if(!entrada){     
      
      led = !led;
      Serial.print("Duración del clic:");
      Serial.println(fin);
        if(contador == 0){
          //Serial.print("Duración del clic:");
        //Serial.println(fin);
        wait = millis();
      }

      contador++;
     
    }
    
 }

   //Serial.println(fin);
  digitalWrite(Salida,led);
  //delay(100);
}

