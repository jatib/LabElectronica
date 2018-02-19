int c = 0;
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(int i=0; i < 100; i++){
    analogWrite(11,porcentaje(i));
    delay(50);
  }

}

int porcentaje(int n){
  n = (256/100)*n;
  return n;  
}

