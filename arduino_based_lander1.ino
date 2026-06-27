/*
 Code for Arduino model planetary lander
 Read distance from an HC-SR04 ultrasonic distance sensor 
 Activate four servo motors to deploy "landing gear" when distance is below a certain threshold
*/

// include the servo library and create servo objects
#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

// define pins
const int trigPin = 7; // HC-SR04 trigger pin
const int echoPin = 8; // HC-SR04 echo pin
// servo pins
const int servo1Pin = 2;
const int servo2Pin = 3;
const int servo3Pin = 4;
const int servo4Pin = 5;

// threshold distance to deploy landing gear
const int thresh = 150;

// angles for servos
const int angle1 = 0;
const int angle2 = 160;

void setup() { // setup code that only runs once
  // attach servo objects to pins
  servo1.attach(servo1Pin);
  servo2.attach(servo2Pin);
  servo3.attach(servo3Pin);
  servo4.attach(servo4Pin);
  // set sensor pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // initialize serial communication:
  //Serial.begin(9600);

  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
}

void loop() {
  // establish variables for duration of the ping, and the distance result in inches and centimeters:
  long duration, inches, cm;

  // send trigger pulse to sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // read echo pulse from sensor
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  if(cm<thresh){
    servo1.write(angle2);
    servo2.write(angle2);
    servo3.write(angle2);
    servo4.write(angle2);
  }
  else{
    servo1.write(angle1);
    servo2.write(angle1);
    servo3.write(angle1);
    servo4.write(angle1);
  }
  // print out the distance - useful for testing your sensor, but comment out this code
  // when testing your lander
  /*
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  */

  // remove or shorten delay when testing your lander 
  delay(5);
}

// functions to convert time in microseconds to distance in inches or cm
// based on Arduino PING example code, also used for HC-SR04

long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: https://www.parallax.com/package/ping-ultrasonic-distance-sensor-downloads/
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}
