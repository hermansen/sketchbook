#include <Servo.h>

int valueIn = 0;
int valueOut = 0;
Servo servo_3;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  servo_3.attach(3);

}

void loop()
{
  valueIn = 0.01723 * readUltrasonicDistance(7, 7);
  Serial.println(valueIn);
  valueOut = map(valueIn, 0, 333, 0, 180);
  servo_3.write(valueOut);
  Serial.println(valueOut);
  delay(10); // Delay a little bit to improve simulation performance
}
