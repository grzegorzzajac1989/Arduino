#include <NewPing.h>

//Tell the Arduino where the sensor is hooked up
NewPing sonar(12, 11);

int enableA = 9;
int pinA1 = 6;
int pinA2 = 5;

int enableB = 10;
int pinB1 = 4;
int pinB2 = 3;

long inches;

void setup() {
pinMode(enableA, OUTPUT);
pinMode(pinA1, OUTPUT);
pinMode(pinA2, OUTPUT);

pinMode(enableB, OUTPUT);
pinMode(pinB1, OUTPUT);
pinMode(pinB2, OUTPUT);
}

void loop() {

//Run the motors at slightly less than full power
analogWrite(enableA, 200);
analogWrite(enableB, 200);

//Ping the sensor and determine the distance in inches
inches = sonar.ping_in();

//If the robot detects an obstacle less than four inches away, it will back up, then turn left; if no obstacle is detected, it will go forward
if (inches < 4) {
analogWrite(enableA, 255);
analogWrite(enableB, 255);
backward(600);
coast(200);
turnLeft(600);
coast(200);}
else {
forward(1);

}
}

//Define high-level H-bridge commands

void enableMotors()
{
motorAOn();
motorBOn();
}

void disableMotors()
{
motorAOff();
motorBOff();
}

void forward(int time)
{
motorAForward();
motorBForward();
delay(time);
}

void backward(int time)
{
motorABackward();
motorBBackward();
delay(time);
}

void turnLeft(int time)
{
motorABackward();
motorBForward();
delay(time);
}

void turnRight(int time)
{
motorAForward();
motorBBackward();
delay(time);
}

void coast(int time)
{
motorACoast();
motorBCoast();
delay(time);
}

void brake(int time)
{
motorABrake();
motorBBrake();
delay(time);
}
//Define low-level H-bridge commands

//enable motors
void motorAOn()
{
digitalWrite(enableA, HIGH);
}

void motorBOn()
{
digitalWrite(enableB, HIGH);
}

//disable motors
void motorAOff()
{
digitalWrite(enableB, LOW);
}

void motorBOff()
{
digitalWrite(enableA, LOW);
}

//motor A controls
void motorAForward()
{
digitalWrite(pinA1, HIGH);
digitalWrite(pinA2, LOW);
}

void motorABackward()
{
digitalWrite(pinA1, LOW);
digitalWrite(pinA2, HIGH);
}

//motor B controls
void motorBForward()
{
digitalWrite(pinB1, HIGH);
digitalWrite(pinB2, LOW);
}

void motorBBackward()
{
digitalWrite(pinB1, LOW);
digitalWrite(pinB2, HIGH);
}

//coasting and braking
void motorACoast()
{
digitalWrite(pinA1, LOW);
digitalWrite(pinA2, LOW);
}

void motorABrake()
{
digitalWrite(pinA1, HIGH);
digitalWrite(pinA2, HIGH);
}

void motorBCoast()
{
digitalWrite(pinB1, LOW);
digitalWrite(pinB2, LOW);
}

void motorBBrake()
{
digitalWrite(pinB1, HIGH);
digitalWrite(pinB2, HIGH);
}

