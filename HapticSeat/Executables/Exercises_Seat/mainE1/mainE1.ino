/*
 * JMIR '17 paper in-car movements part 1
 * Author:
 * Date:
 */
 
#include "HapticSeat.h"
#include "ExercisesHS.h"


// A0, A1 are pre-defined as analaog inputs for first row and col.
// Note A5,A6 are INACTIVE.
#define BUTT1_PIN A2
#define BUTT2_PIN A3
#define BUTT3_PIN A4
#define BUTT4_PIN A5
#define BUTT5_PIN A6


void setup() {
  Serial.begin(9600);

  // Setup input pins
  pinMode(BUTT1_PIN, INPUT_PULLUP);
  pinMode(BUTT2_PIN, INPUT_PULLUP);
  pinMode(BUTT3_PIN, INPUT_PULLUP);
  pinMode(BUTT4_PIN, INPUT_PULLUP);

  // Setup output pins
  resetPins();
}

/*
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * THIS IS WHERE YOU WILL ASSIGN ACTIONS TO BUTTONS.
 * THERE ARE 8 VIBRATIONS, BUT ONLY 4 BUTTONS.
 * RUN ONLY THE FIRST 4 IF STATEMENTS FIRST.
 * (COMMENT OUT THE SECOND 4).
 * THEN COMMENT OUT THE FIRST 4 AND RUN THE SECOND 4.
 * BUTTON 1 CORRESPONDS TO THE BUTTON ON THE VERY SIDE OF THE REMOTE.
 */


void loop() {
  int time = 200;

  if (digitalRead(BUTT1_PIN) == LOW) {
    sideStretch();
  }

  if (digitalRead(BUTT2_PIN) == LOW) {
    backTwist();
  }

  if (digitalRead(BUTT3_PIN) == LOW) {
    dragonBreath(6, 1); 
  }

  if (digitalRead(BUTT4_PIN) == LOW) { 
    fourCountBreath(5, 2);
  }
}


    
