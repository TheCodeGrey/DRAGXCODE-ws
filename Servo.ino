#include <Servo.h>

// Create a servo object
Servo myServo;

// Define pin numbers
const int potPin = A0; // Potentiometer connected to analog pin A0
const int servoPin = 9;  // Servo control pin connected to digital pin 9

void setup() {
  // Attach the Servo variable to a pin
  myServo.attach(servoPin);
  // Initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // Read the value from the potentiometer
  int potValue = analogRead(potPin);
  // Map the potentiometer value from 0-1023 to 0-180 degrees
  int angle = map(potValue, 0, 1023, 0, 180);
  
  // Set the servo position based on the mapped value
  myServo.write(angle);

  // Print the angle to the serial monitor
  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print("\tServo Angle: ");
  Serial.println(angle);

  // Wait for a bit to slow down the serial output
  delay(15);
}
