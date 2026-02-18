#include <Arduino.h>
#include<Servo.h>

Servo myservo;

int trg_pin = 8;
int ech_pin = 10;


void setup() {
    pinMode(trg_pin,OUTPUT);
    pinMode(ech_pin,INPUT);
    myservo.attach(5);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trg_pin,HIGH);
    delayMicroseconds(2);
    digitalWrite(trg_pin,LOW);
    delayMicroseconds(10);
    digitalWrite(trg_pin,HIGH);
    long duration = pulseIn(ech_pin,HIGH);
    float distance = duration*(0.0343/2);
    if(distance<=15){
        myservo.write(180);

    }else{
        myservo.write(0);
    }
    Serial.print("Distance");
    Serial.print(distance);
    Serial.println("CM");
    delay(100);
}