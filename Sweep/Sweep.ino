/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

// # Hardware Connection:
// #        PIR Sensor    -> Digital pin 2
// #        Servo -> Digital pin 9
// #

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sensorPin = 2;
int sensorValue = 0;        // value read from the pot
int oldstate = 0;

void setup() {
  pinMode(sensorPin,INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);

  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {

  int state = digitalRead(sensorPin);
  if(state!=oldstate){
    if(state == 1){
        for (pos = 0; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
          // in steps of 1 degree
          myservo.write(pos);              // tell servo to go to position in variable 'pos'
          delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
    else{
        for (pos = 135; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(15);                       // waits 15ms for the servo to reach the position
        }
      }
  }
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(state);
  Serial.print("\n");

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(3000);

  int oldstate = state;
}
