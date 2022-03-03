const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup() {
  // open a connection between Arduino and PC
  // 9600 is speed at bits per second
  // utilize serial monitor to view transmitted data
  Serial.begin(9600); // open a serial port

  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT); // set as output pins
    digitalWrite(pinNumber, LOW); // set as LOW for pins
  }
}

void loop() {
  // store data read from sensor
  // read using analogRead, arg is pin to take voltage reading on
  // value is representation of voltage on pin is value between 0 and 1023
  int sensorVal = analogRead(sensorPin);

  // Send information from Arduino to PC
  // In this case, print out value as string
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  // convert ADC (analog to digital converter) reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;

  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  // convert voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  Serial.println(temperature); // adds newline

  if (temperature < baselineTemp + 2) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
