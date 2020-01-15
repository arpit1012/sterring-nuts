#include<SoftwareSerial.h>
#include<Servo.h>
#define tx 2
#define rx 3
Servo myservo;

int in1=5;
int in2=6;
int pos=90;
char command;
int pos1=90;
int pos2=90;
SoftwareSerial btSerial(tx,rx);


void setup() {
Serial.begin(9600);
btSerial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
myservo.attach(9);


}

void loop() {
  // put your main code here, to run repeatedly:
  if(btSerial.available()){
  command=btSerial.read();
  Serial.println(command);
  }
if(command=='F'){
  Serial.println("forward");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW );
  myservo.write(90);  
}
if(command=='B'){
  Serial.println("backward");
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH );
  myservo.write(90);  
}
if (command=='G'&&'L'){
  Serial.println("LEFT");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW );
  myservo.write(90); 
  pos1=pos;
  Serial.println(pos);
  if(pos<=110){
   for (pos; pos <=pos1+20; pos += 1) { // goes from 0 degrees to 180 degrees
   
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(5);                       // waits 15ms for the servo to reach the position
  }
  }

}
if (command=='I'&&'R'){
  Serial.println("RIGHT");
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW );
  myservo.write(90); 
  Serial.println(pos);
  pos2=pos;
  if(pos>=70){
   for (pos; pos >=pos2-20; pos -= 1) { // goes from 0 degrees to 180 degrees
   
   myservo.write(pos);              // tell servo to go to position in variable 'pos'
   delay(5);                       // waits 15ms for the servo to reach the position
  }
  }

  
}

if(command=='S')
{
 Serial.println("STOP");
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);

  
}















  
}
