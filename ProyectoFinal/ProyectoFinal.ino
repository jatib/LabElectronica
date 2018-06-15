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
int limiteMovBrazo = 15;
int limiteLoopBrazo = 16;
int limiteLoopCarro = 16;
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
  // **************************************************************************
  //Esta seccion mueve el brazo principal, se puede jugar con el limite
  for(int i=1; i < limiteLoopBrazo; i++){
    // **************************************************************************
    // Elegir la direccion de movimiento del carrito, 
    // para todos los indices de renglon par se mueve en una direccin
    // y para los impar en la otra, garantizando que al final de cada movimiento
    // el carro regrese.
    // **************************************************************************
    sentido = rotacion(i);
      // **************************************************************************
      // Esta seccion mueve el carrito principal se  puede jugar con el limite
      // para ajustar el movimiento 
      // **************************************************************************
      for(int j=1; j<limiteLoopCarro;j++){
        // **************************************************************************
        // Con el ciclo while del motor dos controlamos cuanto avanza el carrito
        // y desde esa condicin podemos repetir el movimiento para recorrer todos
        // los agujeros de siembra
        // **************************************************************************
        int s=0;
        int r=0;
  
        while(s < limiteMovCarro){
          moverMotorDos(sentido);
          s++;
        }
        //
        delay(1000);
        
        // **************************************************************************
        // Aqu jugamos con el movimiento del solenoide, su valor minimo es  1
        // **************************************************************************
        while(r<limiteSolenoide){
          solenoid();
          r++;
        }
      //
     }
      // **************************************************************************
      // Movemos el brazo principal, con limiteMovBrazo controlamos cuanto se desplaza
      // **************************************************************************
      while(n<limiteMovBrazo){
        moverMotorUno(1);
        n++;
      }
      n=0;
    }
    // Regresamos el brazo
    n=0;
    while(n<limiteMovBrazo*limiteLoopBrazo){
        moverMotorUno(0);
        n++;
    }
   
    // Regresamos el carro si y solo si 
    // terminamos el ciclo en par
    n=0;
    if(limiteMovCarro%2==0){
      while(n<limiteMovCarro*limiteLoopCarro){
       moverMotorDos(rotacion(limiteMovCarro)); 
      }
    }
    n = 0;
    delay(10000); // Fin del loop
}


// **********************************************
// Funcion para mover el motor grande noten 
// que es sensible a la conexion de los motores
// que declaramos en Setup()

int moverMotorUno(int sens){
    
    digitalWrite( Dir   , sens);
    digitalWrite( Step  , LOW);
    // Asi hacemos un paso
    digitalWrite( Step, HIGH );
    delay(vel1);
    digitalWrite( Step, LOW );
    delay(vel1);
    
}

int moverMotorDos(int sens){
    
    digitalWrite( Dir2   , sens);
    digitalWrite( Step2  , LOW);
    // Asi hacemos un paso 
    digitalWrite( Step2, HIGH );
    delay(vel2);
    digitalWrite( Step2, LOW );
    delay(vel2);
    
}

int solenoid(){
    digitalWrite(solenoidPin, HIGH);      //Encendemos el solenoide
    delay(100);                          //Esperamos 1 segundo
    digitalWrite(solenoidPin, LOW);       //Apagamos el solenoide
    delay(100);
}

int rotacion(int direccion){
  if(direccion%2 == 0){
    direccion = 1;
  }else{
    direccion = 0;
  }
  
  return direccion;
}

