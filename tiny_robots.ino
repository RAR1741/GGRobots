#include "SoftwareSerial.h"
#include "Motor.h"
#include "Servo.h"

SoftwareSerial blue(11,12);

Motor left(3,2);
Motor right(5,4);
Servo kick;

void setup() {
  Serial.begin(9600);
  blue.begin(9600);
  left.setReversed(true);
  right.setReversed(true);
  kick.attach(6);
}

int x, y, s, l, e;
int test;

void loop() {  
  while(blue.available()) {
    char r = blue.read();
    if(r == 'L') {
      blue.read(); //ignore the x
      while(blue.read() != 'Y') {}
      y = blue.parseInt();
      blue.read();
    } else if(r == 'Z') {
      blue.read();
      x = blue.parseInt();
      while(blue.read() != 'z') {}
    } else if(r == 'C') {
      s=1;
    } else if(r == 'c') {
      s=0;
    } else if(r == 'A') {
      l=1;
    } else if(r == 'a') {
      l=0;
    } else if(r == 'E') {
      e=200;
    } else if(r == 'e') {
      e=0;
    }
  }
  while(Serial.available()) {
    test = Serial.parseInt();
    Serial.println(test);
  }
  if(e>0) {
    left.set(-y-x);
    right.set(-y+x);
    //Serial.println((int)(map(l,0,255,110,60)+0.5));
    //lift.write((int)(map(l,0,1,110,60)+0.5));
//    lift.write(((bool)l ? 60 : 110));
//    hand.write(s==1?0:160);
    
    e--;
  } else {
    left.set(0);
    right.set(0);
  }
  kick.write(test);
  delay(10);
}
