#define NOTE_C 261
#define NOTE_D 294
#define NOTE_E 329
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 493
#define NOTE_HIGH_C 523

#define OUTPUT_PIN 8
#define DURATION 1000

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  char input = Serial.read(); 
  switch (input) {
    case 'C':
      playTone(NOTE_C, DURATION);
      break;
    case 'D':
      playTone(NOTE_D, DURATION);
      break;
    case 'E':
      playTone(NOTE_E, DURATION);
      break;
    case 'F':
      playTone(NOTE_F, DURATION);
      break;
    case 'G':
      playTone(NOTE_G, DURATION);
      break;
    case 'A':
      playTone(NOTE_A, DURATION);
      break;
    case 'B':
      playTone(NOTE_B, DURATION);
      break;
    case 'H':
      playTone(NOTE_HIGH_C, DURATION);
      break;
    case ' ':
      // Space character represents a period of silence
      delay(DURATION/4);
      break;
    default:
      // Ignore unsupported characters
      break;
  }
}

void playTone(int note, int duration) {
  int period = 1000000 / note;

  for (int i = 0; i < duration * 1000; i += period) {
    digitalWrite(OUTPUT_PIN, HIGH);
    delayMicroseconds(period/2);
    digitalWrite(OUTPUT_PIN, LOW);
    delayMicroseconds(period/2);
  }
}


/* 
 * Melody for "Happy Birthday"
 * Copy one line at a time into the Serial monitor as the buffer is not big enough.
 * Note: There's a mistake in the melody; it should be Bb instead of B.
 * 
 * Example input for "Happy Birthday":
 * ->C C DDD CCC FFF EEEEEEE C C DDD CCC GGG FFFFFFF
 * ->C C HHH AAA FFF EEE DDD B B AAA FFF GGG FFFFFFF
*/
