
int Pin = 12;
boolean entrada = LOW;

void setup() {
  pinMode(Pin,INPUT);
  pinMode(11,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {

  
  entrada = digitalRead(12);
  //digitalWrite(11,entrada);

  if(entrada == 1){
    digitalWrite(11,LOW);     
  }else{
   digitalWrite(11,HIGH);  
  }
  
  
  // put your main code here, to run repeatedly:

}

