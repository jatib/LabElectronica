#define Step 7     // Pin that transmits the "step" order to the board
#define Dir  6     // Pin that indicates the direction of the rotation
#define Step2  9
#define Dir2  8
#define solenoidPin 12   //This is the output pin on the Arduino

int vel1  =   10 ;// Velocidad de rotacion motor 1
int vel2 = 10;//Velocidad de rotacion motor 2
int sentido =   1  ;  // Direccin de la rotacin (0 o 1) (por ahora 
                   // iniciamos en 1, el carro debe estar de lado del 
                   // motor principal(el grande))
int n = 0;
int m = 0;
int limiteMovCarro = 25;
int limiteSolenoide = 1;
//Configuracion de entradas y salidas
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
    // **************************************************************************
    // Elegir la direccion de movimiento del carrito, 
    // para todos los indices de renglon par se mueve en una direccin
    // y para los impar en la otra, garantizando que al final de cada movimiento
    // el carro regrese.
    // **************************************************************************
    if( (i%2) == 0 ){
      sentido = 1;
    }else{
      sentido = 0;
    }
    
      // 
      for(int j=1; j<16;j++){
        //moverCarro(int sens, int limiteMovCarro, int limiteSolenoide, int espera=100)
        //moverCarro(sent,25,10);
        
        int s=0;
        int r=0;
  
        while(s < limiteMovCarro){
          moverMotorDos(sentido);
          s++;
        }
        //
        delay(1000);
  
        while(r<limiteSolenoide){
          solenoid();
          r++;
        }
      //
     }
        
      while(n<250){
        moverMotorUno(1);
        n++;
    }
      n=0;
    }                  //Wait 1 Second
    delay(10000);
}//
// **********************************************
// Funcion para mover el motor grande noten 
// que es sensible a la conexion de los motores

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
    
    //return 1;
}

/*int giro(int a,int sentido=1){ 
  if( (a%2) == 0 ){
      sentido = 1;
    }else{
      sentido = 0;
    }
      
  return sentido;
}
/*
int moverCarro(int sentido, int limiteMovCarro, int limiteSolenoide, int espera=100){
  
  int s=0;
  int r=0;
  
  while(s < limiteMovCarro){
    moverMotorDos(sens);
    s++;
  }
  //
  delay(espera);
  
  while(r<limiteSolenoide){
    solenoid();
    r++;
  }
  //
}

int moverBrazo(int tiempo){
  int r=0;
  while(r<tiempo){
    moverMotorUno(1);
    r++;
  }
}*/
