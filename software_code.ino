// Pin configuration
const int trigPin = 9;      // Ultrasonic sensor TRIG
const int echoPin = 10;     // Ultrasonic sensor ECHO
const int buzzerPin = 6;    // Buzzer
const int redLedPin = 5;    // Red LED

// Distance threshold in cm
const long thresholdDistance = 20;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);

  Serial.begin(9600); // Optional: for debugging
}

void loop() {
  long duration, distance;

  // Send ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  // Check if object is outside proximity
  if (distance > thresholdDistance) {
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    digitalWrite(redLedPin, HIGH); // Turn on red LED
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn off buzzer
    digitalWrite(redLedPin, LOW);  // Turn off red LED
  }

  delay(100); // Small delay for stability
}
