#include <Servo.h>

#define buttonpin 2 // Pin for the door close ( we tested with a button)
#define servopin 9 // Pin for the servo

Servo servo;

int initialLEDs[] = {3, 4, 5, 6}; // Pins for the initial set of LEDs
int secondLEDs[] = {7, 8, 12, 11}; // Pins for the second set of LEDs
//int pos = 0;
bool lightsOn = false;
bool buttonState = false;
bool lastButtonState = false;

void setup() {
  // servo to 0 ( done slower) (initially just had 4 positions but kept adding to slow it down and ended up with a long string)
  servo.attach(servopin);
  servo.write(165);
    delay(1000);
    servo.write(150);
    delay(1000);
    servo.write(135);
    delay(1000);
    servo.write(120);
    delay(1000);
    servo.write(105);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(75);
    delay(1000);
    servo.write(60);
    delay(1000);
    servo.write(45);
    delay(1000);
    servo.write(30);
    delay(1000);
    servo.write(15);
    delay(1000);
    servo.write(0);
    delay(1000);

  // button set up
  pinMode(buttonpin, INPUT_PULLUP);
  
  // set up leds
  for (int i = 0; i < 4; i++) {
    pinMode(initialLEDs[i], OUTPUT);
    digitalWrite(initialLEDs[i], HIGH); // turn on first leds
  }
}

void loop() {
  // is the button pressed
  buttonState = digitalRead(buttonpin);

  // is the button pressed check
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      // if pressed, lights and servo toggle
      toggleLightsAndServo();
    }
    delay(50); 
  }

  lastButtonState = buttonState;
}

void toggleLightsAndServo() {
  if (lightsOn) {
    // Turn off the initial set of LEDs
    for (int i = 0; i < 4; i++) {
      digitalWrite(initialLEDs[i], LOW);
    }

    // turn on the second set of LEDs
    for (int i = 0; i < 4; i++) {
      pinMode(secondLEDs[i], OUTPUT);
      digitalWrite(secondLEDs[i], HIGH);
    }

    // rotate the servo to 180 degrees
    //servo.write(180);
    /*for (pos=0;pos<=180;pos+=45 ) {// slowing this down, but still goes from 0 degrees to 180
    
    servo.write(pos); 
    delay(100);
    }*/
    servo.write(15);
    delay(1000);
    servo.write(30);
    delay(1000);
    servo.write(45);
    delay(1000);
    servo.write(60);
    delay(1000);
    servo.write(75);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(105);
    delay(1000);
    servo.write(120);
    delay(1000);
    servo.write(135);
    delay(1000);
    servo.write(150);
    delay(1000);
    servo.write(165);
    delay(1000);
    servo.write(180);
    delay(1000);

    lightsOn = false; // Update lights status
  } else {
    // Turn off the second set of LEDs
    for (int i = 0; i < 4; i++) {
      digitalWrite(secondLEDs[i], LOW);
    }

    // turn on the initial set of LEDs
    for (int i = 0; i < 4; i++) {
      pinMode(initialLEDs[i], OUTPUT);
      digitalWrite(initialLEDs[i], HIGH);
    }

    // Rotate the servo back to 0 degrees
    //servo.write(0);
    /*for (pos=0;pos<=180;pos-=45 ) {// slowing this down, but still goes from 180 degrees to 0
    
    servo.write(pos); 
    delay(100);
    }*/
    servo.write(165);
    delay(1000);
    servo.write(150);
    delay(1000);
    servo.write(135);
    delay(1000);
    servo.write(120);
    delay(1000);
    servo.write(105);
    delay(1000);
    servo.write(90);
    delay(1000);
    servo.write(75);
    delay(1000);
    servo.write(60);
    delay(1000);
    servo.write(45);
    delay(1000);
    servo.write(30);
    delay(1000);
    servo.write(15);
    delay(1000);
    servo.write(0);
    delay(1000);

    lightsOn = true; // lights on
  }
}