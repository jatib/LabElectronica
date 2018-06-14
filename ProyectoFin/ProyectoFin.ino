// Declaration of variables
#define Step 7     // Pin that transmits the "step" order to the board
#define Dir  6     // Pin that indicates the direction of the rotation
#define Step2  9
#define Dir2  8
int vit  =   1 ;   // Speed of the rotation (smaller means faster rotation)
int sens =   1  ;  // Rotation direction (0 or 1)
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
   
}//
