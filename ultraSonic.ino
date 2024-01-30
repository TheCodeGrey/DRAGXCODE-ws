/** HC-SR04 Ultrasonic Sensor Distance Measurement
by Raed**/

const int trigPin = 11;    // Trigger Pin
const int echoPin = 12;    // Echo Pin
long duration, distanceCm;

void setup() {
  Serial.begin(9600);      // Start Serial Communication at 9600 baud rate
  pinMode(trigPin, OUTPUT); // Set the trigger pin as an output
  pinMode(echoPin, INPUT);  // Set the echo pin as an input
}

void loop() {
  // Trigger the sensor by sending a HIGH pulse of 10 microseconds
  digitalWrite(trigPin, LOW);   // Ensure a clean pulse
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose duration is the time 
  // (in microseconds) from the sending of the ping to the reception of its echo
  duration = pulseIn(echoPin, HIGH);

  // Convert the time into a distance
  distanceCm = duration / 2 / 29.1; // Divide by 29.1 to get distance in cm

  // Print the distance in centimeters
  Serial.print(distanceCm);
  Serial.println(" cm");
  
  delay(250); // Delay between measurements for stability
}
