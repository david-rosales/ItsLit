#include <CapacitiveSensor.h>
#include <Servo.h>

CapacitiveSensor cs1 = CapacitiveSensor(2,3);
CapacitiveSensor cs2 = CapacitiveSensor(2,5);
CapacitiveSensor cs3 = CapacitiveSensor(2,4);  

Servo sx;  // create servo object to control a servo
Servo sy;  // create servo object to control a servo

volatile int timeout = 0;
bool on = true;
int bright = 4;
int xpos = 90;
int ypos = 120;
int xprev = 0;
int yprev = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  sx.attach(9);  // attaches the servo on pin 9 to the servo object
  sy.attach(10);  // attaches the servo on pin 10 to the servo object
  //Timer interrupt setup
  OCR0A = 0xAF;
  TIMSK0 |= _BV(OCIE0A);
}
bool lockout = false;

void loop() {
  // Handle Lights
  long total1 =  cs1.capacitiveSensor(30);
  if(total1>400 && timeout ==0 && !lockout){
    on = ! on;
    lockout = true;
    timeout = 500;
  }else if(total1<400){
    lockout = false;
  }
  long total2 =  cs2.capacitiveSensor(30);
  if(total2>400 && timeout ==0){
    bright--;
    if(bright<1){
      bright = 1;
    }
    timeout = 500;
  }
  long total3 =  cs3.capacitiveSensor(30);
  if(total3>400 && timeout ==0){
    bright++;
    if(bright>8){
      bright = 8;
    }
    timeout = 500;
  }
  int width = 0;
  if(on){
    width = (1<<bright)-1;
  }
  analogWrite(11,width);

  //Handle Servos
  if(Serial.available()>0){
    String data = Serial.readStringUntil('\n');
    int split = data.indexOf(' ');
    if(split>0){
      int x = data.substring(0,split).toInt();
      int y = data.substring(split+1).toInt();

      xpos += x/70+(x-xprev)/180;
      if(xpos>180){
        xpos = 180;
      }
      if(xpos<0){
        xpos = 0;
      }
      ypos -= y/70+(y-yprev)/180;
      if(ypos>140){
        ypos = 140;
      }
      if(ypos<90){
        ypos = 90;
      }
      xprev = x;
      yprev = y;
      sx.write(xpos);
      sy.write(ypos);
    }
  }
  delay(10);
}

SIGNAL(TIMER0_COMPA_vect) 
{
  if(timeout>0){
    timeout--;
  }
}
