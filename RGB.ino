//RGB LED
const int r = 3;
const int g = 5;
const int b = 6;

//Color Sensor
const int S0 =8;
const int S1 =9;
const int S2 =10;
const int S3 =11;
const int OUT = 12;

//Get color from sensor
int getR =0;
int getG =0;
int getB =0;
int getN =0;


void setup() {
  Serial.begin(9600);
  pinMode(b, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(S0,OUTPUT);
  pinMode(S1,OUTPUT);
  pinMode(S2,OUTPUT);
  pinMode(S3,OUTPUT);
  pinMode(OUT,INPUT);

 // Escala de frequencia para 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}
void ledOff(){
  digitalWrite(r, LOW);
  digitalWrite(g, LOW);
  digitalWrite(b, LOW);
  }
void greenFunction(){
  analogWrite(r, 0);
  analogWrite(b, 0);
  analogWrite(g, 255);
}

void readColor(){

  //Read red filter
  digitalWrite(S2, LOW); 
  digitalWrite(S3, LOW); 
  if(digitalRead(OUT) == HIGH){ 
    getR = pulseIn(OUT, LOW); 
  } else {
    getR = pulseIn(OUT, HIGH); // duracao do pulso na saida
  }

//Read blue filter
  digitalWrite(S3, HIGH); 
  if(digitalRead(OUT) == HIGH){ 
    getB = pulseIn(OUT, LOW); 
  } else {
    getB = pulseIn(OUT, HIGH); // duracao do pulso na saida
  }

  //Read green filter
  digitalWrite(S2, HIGH); 
  if(digitalRead(OUT) == HIGH){ 
    getG = pulseIn(OUT, LOW); 
  } else {
    getG = pulseIn(OUT, HIGH); // duracao do pulso na saida
  }
  //Read NO filter
  digitalWrite(S2, HIGH); 
  digitalWrite(S3, LOW); 
  
  if(digitalRead(OUT) == HIGH){ 
    getN = pulseIn(OUT, LOW); 
  } else {
    getN = pulseIn(OUT, HIGH); // duracao do pulso na saida
  }

greenFunction();
        
  if(getG <60){
    Serial.println("verde");
    Serial.println("tempo");
  }
  Serial.println("===============================================================================");
}
void loop() {
  readColor();
  
}
