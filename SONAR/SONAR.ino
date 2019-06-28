#include<Servo.h>
const int trigPin = 10;
const int ecoPin = 11;
long duration;
int distance;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT);
pinMode(ecoPin, INPUT);
Serial.begin(9600);
myServo.attach(12);
}

void loop() {
  // put your main code here, to run repeatedly:
for(int i=15;i<=165;i++)
{myServo.write(i);
delay(30);
distance=caldistance();
Serial.print(i);
Serial.print(",");
Serial.print(distance);
Serial.print(".");
}

for(int i=165;i>=15;i--)
{myServo.write(i);
delay(30);
distance=caldistance();
Serial.print(i);
Serial.print(",");
Serial.print(distance);
Serial.print(".");
}
}

int caldistance(){
digitalWrite(trigPin,LOW);
delayMicroseconds(3);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration = pulseIn(ecoPin,HIGH);
distance = duration*0.034/2;
return distance;
}
