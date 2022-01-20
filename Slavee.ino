/*Slave*/
#include <SoftwareSerial.h>
#include <Servo.h>
Servo myServo;
SoftwareSerial BtSerial(10, 11);
char gelen;
int led=13;
int motora1 = 2;
int motora2 = 3;
void setup() {
 myServo.attach(9);
BtSerial.begin(9600);
Serial.begin(9600);
pinMode(13,OUTPUT);
  pinMode(motora1, OUTPUT);
  pinMode(motora2, OUTPUT);
}

void loop() {
  
if(BtSerial.available() > 0)
  {
                //haberlşeme varsa kuyruktaki verileri değişkene yazdık
    gelen = BtSerial.read();
    Serial.println(gelen);
    if(gelen=='i'){
      Serial.print("ileri Yön");
      digitalWrite(led,LOW);
      analogWrite(motora2,100);
      }
     else if(gelen=='g'){
      digitalWrite(led,HIGH);
      Serial.print("geri Yön");
      analogWrite(motora2,0);
      }
      else if(gelen=='r'){
       myServo.write(0);
       delay(500);
        analogWrite(motora2,40);
      Serial.print("sağ Yön");
      }
      else if(gelen=='l'){
       myServo.write(90);
       delay(500);
       analogWrite(motora2,40);
      Serial.print("sol Yön");
      }
      else{ analogWrite(motora2,0);}
      

}
}
