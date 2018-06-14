/*const int dirPin = 6;
const int stepPin = 7;
const int steps = 200;
int stepDelay;

void setup() {
	// Marcar los pines como salida
	pinMode(dirPin, OUTPUT);
	pinMode(stepPin, OUTPUT);
}

void loop() {
	//Activar una direccion y fijar la velocidad con stepDelay
	digitalWrite(dirPin, HIGH);
	stepDelay = 250;
	// Giramos 200 pulsos para hacer una vuelta completa
	for (int x = 0; x < 200; x++) {
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(stepDelay);
		digitalWrite(stepPin, LOW);
		delayMicroseconds(stepDelay);
	}
	delay(1000);

	//Cambiamos la direccion y aumentamos la velocidad
	digitalWrite(dirPin, LOW);
	stepDelay = 150;
	// Giramos 400 pulsos para hacer dos vueltas completas
	for (int x = 0; x < 400; x++) {
		digitalWrite(stepPin, HIGH);
		delayMicroseconds(stepDelay);
		digitalWrite(stepPin, LOW);
r		delayMicroseconds(stepDelay);
	}
	delay(1000);
}*/

// Declaration of variables
#define Step 7     // Pin that transmits the "step" order to the board
#define Dir  6     // Pin that indicates the direction of the rotation
#define Step2  9
#define Dir2  8
int vit  =   1 ;   // Speed of the rotation (smaller means faster rotation)
int sens =   0  ;  // Rotation direction (0 or 1)
int solenoidPin = 12;                    //This is the output pin on the Arduino


void setup(){
  //pinMode( Step  , OUTPUT );
  //pinMode( Dir   , OUTPUT );
  pinMode(solenoidPin, OUTPUT);
  pinMode( Step2  , OUTPUT );
  pinMode( Dir2   , OUTPUT );
}
void loop()
{
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(1000);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
    delay(1000);                          //Wait 1 Second
    //Primary motor
    digitalWrite( Dir   , sens);
    digitalWrite( Step  , LOW);
    // Fabrication d'un "Pas"
    digitalWrite( Step, HIGH );
    delay(vit);
    digitalWrite( Step, LOW );
    delay(vit);
    //Secondary Motor
    digitalWrite( Dir2   , sens);
    digitalWrite( Step2  , LOW);
    // Fabrication d'un "Pas"
    digitalWrite( Step2, HIGH );
    delay(vit);
    digitalWrite( Step2, LOW );
    delay(vit);
}//
