const int greenLEDpin = 9;
const int blueLEDpin = 10;
const int redLEDpin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

//variables to store the sensor readings
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  //define the pins as outputs
  pinMode(greenLEDpin, OUTPUT);
  pinMode(blueLEDpin, OUTPUT);
  pinMode(redLEDpin, OUTPUT);
}

void loop() {
  //read the sensor values and store them
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);

  //print the values
  Serial.print("Raw Sensor Values \t red: ")
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);

  //converting the sensor readings from a value of 0-1023 to a value between 0-255
  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  //255 = HIGH constantly
  //127 = HIGH only half the time => LED will dimmer
  //0 = LOW constantly

  //print out the values after conversion
  Serial.print("Mapped Sensor Values \t red: ")
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);

  //the function that changes the LED's brightness via PWM is analogWrite(the pin to write to, value between 0 and 255)
  analogWrite(redLEDpin, redValue);
  analogWrite(greenLEDpin, greenValue);
  analogWrite(blueLEDpin, blueValue);
}
