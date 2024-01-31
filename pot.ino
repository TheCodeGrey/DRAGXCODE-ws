/** potentiometer as analog input 
by Raed**/

const int potPin = A0; // Potentiometer connected to A0 
int potValue = 0;      // Variable to store the potentiometer value
int throttle = 0;      // Variable to store the PWM value

void setup() {
  Serial.begin(9600);        // Start Serial communication at 9600 baud rate
}

void loop() {
  potValue = analogRead(potPin);             // Read the potentiometer value
  throttle = map(potValue, 0, 1023, 0, 100); // Map the pot value to a throttle value 0-100%

  // Always display the PWM value
  Serial.print("throttle at: ");
  Serial.print(throttle);
  Serial.println("%");

  
  

  // Additionally, check if the potentiometer is fully clockwise
  if (potValue > 1000) {
    Serial.println("Please calm down, you are at full speed!!");
  }

  delay(100); // Short delay for stability and readability
}
