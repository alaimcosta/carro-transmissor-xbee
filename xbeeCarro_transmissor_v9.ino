#include <Arduino.h>
#include<XBee.h>
#include<SoftwareSerial.h>

SoftwareSerial XBEE1(3,4);

const int eixoX = A0;
const int eixoY = A1;
const int stop = 2;

XBee xbee = XBee();

void setup() {
  
  Serial.begin(9600);
  XBEE1.begin(9600);
  xbee.begin(Serial);  
  Serial.println("Iniciando........");
  pinMode (stop, INPUT_PULLUP); 
  
}

void loop() {
  int x = analogRead(eixoX);
  int y = analogRead(eixoY);
  int posStop = digitalRead(stop);
  
  if (x == 0) {
    XBEE1.print(1);
    //Serial.println("1");
  } else if (x == 1023) {
    XBEE1.print(2);
    //Serial.println("2");
  }else if (y == 0) {
    XBEE1.print(3);
    //Serial.println("3");
  } else if (y == 1023) {
    XBEE1.print(4);
    //Serial.println("4");
  }else if (digitalRead(posStop) == HIGH) {
    XBEE1.print(0);
    //Serial.println("0");
  }  
  delay(50);
}
