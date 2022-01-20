
/*Master*/
#include <SoftwareSerial.h>
 
SoftwareSerial BtSerial(10, 11);
char giden;
int xPin = A0; 
int yPin = A1; 

 
int xPozisyon;
int yPozisyon;

 
void setup() {
Serial.begin(9600);
BtSerial.begin(9600);
pinMode(xPin, INPUT);
pinMode(yPin, INPUT);

}
 
void loop() {
xPozisyon = analogRead(xPin);
yPozisyon = analogRead(yPin);





if(BtSerial.available() > 0)
  {
    if(xPozisyon>800){
  Serial.println("İleri Yön");
  BtSerial.write("i");
  }
else if(xPozisyon<300){
  Serial.println("Geri  Yön");
  BtSerial.write("g");
  }
 else  if(yPozisyon>800){
  Serial.println("Sağ Yön");
  BtSerial.write("r");
  }
else if(yPozisyon<300){
  Serial.println("Sol  Yön");
  BtSerial.write("l");
  }
  else if((xPozisyon<800) &&(xPozisyon<300)&&(yPozisyon<800) &&(yPozisyon<300)){
    BtSerial.write("g");
    }
 

delay(500);
  }}
