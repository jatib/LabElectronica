#define Step 7     // Pin that transmits the "step" order to the board
#define Dir  6     // Pin that indicates the direction of the rotation
#define Step2  9
#define Dir2  8
#define solenoidPin 12   //This is the output pin on the Arduino

int vel1  =   10 ;// Velocidad de rotacion motor 1
int vel2 = 10;//Velocidad de rotacion motor 2
int sent =   1  ;  // Direccin de la rotacin (0 o 1)
int n = 0;
int m = 0;

void setup(){
  
  pinMode( Step  , OUTPUT );
  pinMode( Dir   , OUTPUT );
  pinMode(solenoidPin, OUTPUT);
  pinMode( Step2  , OUTPUT );
  pinMode( Dir2   , OUTPUT );
}

void loop()
{
  
  for(int i=1; i<16; i++){
    // Elegir la direccion de movimiento del carrito, 
    // para todos los indices de renglon par se mueve en una direccin
    // y para los impar en la otra, garantizando que al final de cada movimiento
    // el carro regrese.
    if( i%2 == 0 )
      sent = 1;
    else
      sent = 0;
      //
      for(int j=1; j<16;j++){
        //
        while(n<1){
          while(m < 15){
            moverMotorDos(sent);
            m++;
          }
          //
          m = 0;
          delay(100);
          //
          while(m<1){
            solenoid();
            m++;
          }
          //
          m=0;
          n++;
        }
        n=0;
       }
      while(n<250){
        moverMotorUno(1);
        n++;
    }
      n=0;
    }                  //Wait 1 Second
    delay(10000);
}//

int moverMotorUno(int sens){
    
    digitalWrite( Dir   , sens);
    digitalWrite( Step  , LOW);
    // Fabrication d'un "Pas"
    digitalWrite( Step, HIGH );
    delay(vel1);
    digitalWrite( Step, LOW );
    delay(vel1);
    
}

int moverMotorDos(int sens){
    
    digitalWrite( Dir2   , sens);
    digitalWrite( Step2  , LOW);
    // Fabrication d'un "Pas"
    digitalWrite( Step2, HIGH );
    delay(vel2);
    digitalWrite( Step2, LOW );
    delay(vel2);
    
}



int solenoid(){
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(100);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
    delay(100);
}
