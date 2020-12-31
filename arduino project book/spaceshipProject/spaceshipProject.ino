int switchState = 0;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  //checks pin for input
  switchState = digitalRead(2);
  //can be 1 = HIGH (there is voltage)
  //can be 0 = LOW (there is no voltage)

  if(switchState == 0)
  //if the button isn't pressed
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else
  //the button is pressed
  {
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  delay(250);
}
