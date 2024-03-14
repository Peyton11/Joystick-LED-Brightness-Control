/*
  main.ino

  Changes the brightness of an LED using an Arduino and joystick.
*/

#define VRX_PIN A0 // VRX connected to A0
#define VRY_PIN A1 // VRY connected to A1
#define SW_PIN A2 // SW connected to A2
#define LED_PIN 6 // LED connected to D6

int xValue = 0; // joystick x-value
int yValue = 0; // joystick y-value
int swValue = 0; // joystick click value

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT); // LED pin set to output
}

void loop() {

  // Reads the values of the joystick. They both have a max value of 1023.
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  swValue = analogRead(SW_PIN);

  // Roughly calculates 0-255. (It's really 1023 / 4 =255.75). So, if it calculates over 255, set it to 255.
  int brightness = xValue / 4;
  if (brightness > 255)
    brightness = 255;

  // Turn the LED on at that brightness 0-255.
  analogWrite(LED_PIN, brightness);

  // Print the current values of the joystick
  Serial.print("x = ");
  Serial.println(xValue);
  Serial.print("y = ");
  Serial.println(yValue);
  Serial.print("sw = ");
  Serial.println(swValue);
}
