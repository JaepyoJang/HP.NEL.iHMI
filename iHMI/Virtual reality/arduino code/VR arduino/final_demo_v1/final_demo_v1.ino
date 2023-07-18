#include <SoftwareSerial.h>

int raw1 = 0; int raw2 = 0; int raw3 = 0; int raw4 = 0; int raw5 = 0; 
String ch;
String vib1;
String vib2;
String vib3;
String vib4;
String vib5;
   

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  
   pinMode(8,OUTPUT);
   pinMode(7,OUTPUT);
   pinMode(6,OUTPUT);
   pinMode(5,OUTPUT);
   pinMode(4,OUTPUT);
   Serial.setTimeout(10);
   delay(10);
 
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read sensor data:
  int raw1 = analogRead(A0);
  int raw2 = analogRead(A1);
  int raw3 = analogRead(A2);
  int raw4 = analogRead(A3);
  int raw5 = analogRead(A4);

Serial.print(raw1);
Serial.print(",");
Serial.print(raw2);
Serial.print(",");
Serial.print(raw3);
Serial.print(",");
Serial.print(raw4);
Serial.print(",");
Serial.println(raw5);
delay(200);

 // read unity data
   if(Serial.available()){
ch = Serial.readString();
vib1 = ch.substring(0,1);
vib2 = ch.substring(1,2);
vib3 = ch.substring(2,3);
vib4 = ch.substring(3,4);
vib5 = ch.substring(4,5);

delay(10);

 // vibrator control
   if(vib1 == "1" )
    {
        digitalWrite(4,HIGH);   
    }
     else {
      digitalWrite(4,LOW);
    }

     if(vib2 == "1" )
    {
        digitalWrite(5,HIGH);   
    }
     else {
      digitalWrite(5,LOW);
    }

     if(vib3 == "1" )
    {
        digitalWrite(6,HIGH);   
    }
     else {
      digitalWrite(6,LOW);
    }

     if(vib4 == "1" )
    {
        digitalWrite(7,HIGH);   
    }
     else {
      digitalWrite(7,LOW);
    }

     if(vib5 == "1" )
    {
        digitalWrite(8,HIGH);   
    }
     else {
      digitalWrite(8,LOW);
    }
   }
   delay(10);

  


}
