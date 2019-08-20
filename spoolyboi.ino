// spoolyboi

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
const int bzrPin = 3;
int freq = 32;
int bottomfreq = 31;
int level1 = 100;
int level2 = 200;
int level3 = 300;
int maxcharge = 6969;
int increment = 8;
int decrement = 4;
int howfast = 3;          // how quickly it charges and discharges

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (freq <= bottomfreq) {
    noTone(bzrPin);
  } else {
    tone(bzrPin, freq);
  }

  // increase frequency and light up LED
  // when button is pressed
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    if (freq <= maxcharge - increment) {
      freq = freq + increment;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (freq > bottomfreq) {
      freq = freq - decrement;
    }
  }

  // slow everything down a bit
  delay(howfast);

  // come to a slow stop
  if (freq < level1 && freq > bottomfreq) {
    delay(3);
  } else if (freq < level2 && freq > level1) {
    delay(2);
  } else if (freq < level3 && freq > level2) {
    delay(1);
  }


}
