const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize serial communications:
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);

  // if the analog value is high enough, turn on the LED:
  if (analogValue > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  // print the analog value:
  Serial.println(analogValue);
  delay(1);        // delay in between reads for stability
}
 61  
task4.im.txt
@@ -0,0 +1,61 @@
// Declaring Pins
const int buzzerPin = 5;
const int ledPin = 6;
const int motionPin = 7;
const int buttonPin = 12;

// Setting Buzzer mode to False
boolean buzzer_mode = false;

// For LED
int ledState = LOW;
long previousMillis = 0; 
long interval = 100;  // Interval at which LED blinks

void setup()
{
  //The Following are our output
  pinMode(ledPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);

  //Button is our Input
  pinMode(buttonPin, INPUT);

  // Wait before starting the alarm
  delay(5000);
}

void loop()
{
  // To chech whether the motion is detected or not
  if (digitalRead(motionPin)) {
    buzzer_mode = true; 
  }

  // If alarm mode is on,blink our LED
  if (buzzer_mode){
    unsigned long currentMillis = millis();
    if(currentMillis - previousMillis > interval) {
      previousMillis = currentMillis;   
      if (ledState == LOW)
        ledState = HIGH;
      else
        ledState = LOW;
    // Switch the LED
    digitalWrite(ledPin, ledState);
    }
    tone(buzzerPin,1000);
  }

  // If alarm is off
  if (buzzer_mode == false) {

    // No tone & LED off
    noTone(buzzerPin);  
    digitalWrite(ledPin, LOW);
  }

  // If our button is pressed Switch off ringing and Setup
  int button_state = digitalRead(buttonPin);
  if (button_state) {buzzer_mode = false;}
}