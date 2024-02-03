#define RED_LED 8
#define GREEN_LED 9

void setup() {
  // Set pin configurations
  DDRD = B00000000; // Configure PORTD pins for input
  PORTD = B11111100; // Enable pull-up resistors on PORTD pins

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);

  Serial.begin(9600); // Initialize the serial communication
}

void loop() {
  byte portDValues = PIND;

  Serial.println(portDValues, BIN);
  delay(50);

  int red_on = 0, green_on = 0;

  for (int i = 2; (i <= 7) && (!red_on || !green_on); i++) {
    // Check if any two adjacent pins are HIGH
    if (!red_on && ((portDValues & (1 << i)) && (portDValues & (1 << (i + 1))))) {
      red_on = 1;
    }

    // Check if any two adjacent pins are LOW
    if (!green_on && (!(portDValues & (1 << i)) && !(portDValues & (1 << (i + 1))))) {
      green_on = 1;
    }
  }

  if (red_on) {
    digitalWrite(RED_LED, HIGH);
  } else {
    digitalWrite(RED_LED, LOW);
  }

  if (green_on) {
    digitalWrite(GREEN_LED, HIGH);
  } else {
    digitalWrite(GREEN_LED, LOW);
  }

  delay(50);
}
