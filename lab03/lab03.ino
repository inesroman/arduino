#define IN_PIN A0
#define CHASE_SPEED_MIN 1
#define CHASE_SPEED_MAX 200
#define NUM_LEDS 6
#define OUT_PIN 8

short int chaseSpeed;
short int i;

void setup() {
  pinMode(IN_PIN, INPUT);
  for(int i = 0; i < NUM_LEDS; i++) {
    pinMode(OUT_PIN + i, OUTPUT);
    digitalWrite(OUT_PIN + i, LOW);
  }
}

void loop() {
  chaseSpeed = map(analogRead(IN_PIN), 0, 1023, CHASE_SPEED_MIN, CHASE_SPEED_MAX);
  for(i = 0; i < NUM_LEDS; i++) {
    digitalWrite(OUT_PIN + i, HIGH);
    delay(chaseSpeed);
    digitalWrite(OUT_PIN + i, LOW);
  }
  for(i = NUM_LEDS-1; i >= 0; i--) {
    digitalWrite(OUT_PIN + i, HIGH);
    delay(chaseSpeed);
    digitalWrite(OUT_PIN + i, LOW);
  }
}
