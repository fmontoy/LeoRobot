#include <Servo.h>
char val;
//Motor 1(pwm = 13)
int in4 = 50;
int in3 = 46;

//Motor 2(pwm = 10)
int in2 = 42;
int in1 = 38;

//Servo
Servo myservo;
int pos = 0; 





void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  //Servo
  myservo.attach(9);
  //Motor 1
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  //Motor 2
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  while(Serial1.available() > 0) {
     val = Serial1.read();
     Serial.println(val);
     switch(val){
        case 'u':
          adelante();
          break;
          
        case 'd':
          atras();
          break;
          
        case 'p':
          parar();
          break;
          
        case 'l':
          left();
          break;
          
        case 'r':
          right();
          break;
        
        case 'c':
          coger();
          break;
        
        case 's':
          soltar();
          break;   
        
        default:
          break;
        
     }
  }
      
  
}

void atras() {
  analogWrite(2, 120);
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(4, 120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void adelante() {
  analogWrite(2, 50);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  analogWrite(4, 50);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void parar(){
  analogWrite(4,0);
  analogWrite(2,0);
}

void left(){
  analogWrite(2, 0);
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  analogWrite(4, 50);
}

void right(){
  analogWrite(2, 50);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(4, 0);
}

void coger() {
for(pos = 0; pos <= 180; pos += 1){                                 
    myservo.write(pos);              
    delay(10);                        
  }             
}
void soltar(){
   for(pos = 180; pos>=0; pos-=1){                                
    myservo.write(pos);              
    delay(10);                      
  }                    
}

