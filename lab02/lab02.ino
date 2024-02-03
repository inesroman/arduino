#define RED_LED 8
#define GREEN_LED 9
#define BLUE_LED 10
#define SW_PIN 4

int count = 0;
boolean curState = false;
boolean prevState = false;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(SW_PIN, INPUT_PULLUP);
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void loop() {
  prevState = curState;
  if(digitalRead(SW_PIN) == LOW) {
    curState = true;
    if(prevState != curState) {
      count = (count + 1) % 6;
      if(count == 1) {
        digitalWrite(RED_LED, HIGH);
      } else if(count == 2) {
        digitalWrite(GREEN_LED, HIGH);
      } else if(count == 3) {
        digitalWrite(BLUE_LED, HIGH);
      } else if(count == 4) {
        digitalWrite(RED_LED, LOW);
      } else if(count == 5) {
        digitalWrite(GREEN_LED, LOW);
      } else if(count == 0) {
        digitalWrite(BLUE_LED, LOW);
      }
    } 
  } else {
    curState = false;
  }
  delay(50);
}
