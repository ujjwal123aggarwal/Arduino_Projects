#define joystickX A0
#define joyatickY A1
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
 
  xValue = analogRead(joystickX);
  yValue = analogRead(joystickY);
 
 
  Serial.print(xValue);
  Serial.print("\n");
  Serial.println(yValue);
}
