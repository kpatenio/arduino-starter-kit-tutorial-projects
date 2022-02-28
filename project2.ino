/*
 * Arduino Starter Kit - project 2
 * @author: kpatenio
 * 
 * This is project 2 for the starter kit (Spaceship Interface).
 * In the original project, the green LED lights up when no button is pressed.
 * When the switch is pressed (and held), both red LEDs will alternate and light up.
 * 
 * I made a personal change here to make the green LED blink while the switch is not pressed.
 */

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int switchState = 0;

  // personal refactoring: assuming certain LEDS
  // are assigned specific pin numbers
  int greenLED = 3;
  int redLEDPin5 = 5;
  int redLEDPin4 = 4;

  // Read voltage of pin 2; 0 or 1 for low or high respectively.
  // Recall that if current goes through pin 2, that means it was
  // permitted to be hit after having pressed the button.
  switchState = digitalRead(2);

  // button not pressed
  if (switchState == LOW) {
    // If running before, turn off red LEDs
    digitalWrite(redLEDPin4, LOW);
    digitalWrite(redLEDPin5, LOW);

    // Make green LED blink 
    digitalWrite(greenLED, HIGH);
    delay(250);
    digitalWrite(greenLED, LOW);
    delay(250);
    digitalWrite(greenLED, HIGH);
  } else { // button is pressed
    digitalWrite(greenLED, LOW);
    digitalWrite(redLEDPin4, LOW);
    digitalWrite(redLEDPin5, HIGH);
    delay(250); // 250 ms

    // Toggle LEDS
    digitalWrite(redLEDPin4, HIGH);
    digitalWrite(redLEDPin5, LOW);
    delay(250);
  }
  // at the end of this, loop will continue
}
