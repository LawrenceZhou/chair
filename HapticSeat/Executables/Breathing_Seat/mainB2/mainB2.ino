/*
 * JMIR '17 paper in-car movements part 2
 * Author: Nur Hamdan
 * Date: Non. 19, 2016
 */
 
#include "HapticSeat.h"
#include "BreathingHS.h"


// A0, A1 are pre-defined as analaog inputs for first row and col.
// Note A5,A6 are INACTIVE.
#define BUTT1_PIN A2
#define BUTT2_PIN A3
#define BUTT3_PIN A4
#define BUTT4_PIN A5
#define BUTT5_PIN A6

// 2-dimensional array of row pin numbers:
const byte colPins[7] = {2, 3, 4, 5, 6, 7, A1};
// 2-dimensional array of column pin numbers:
const byte rowPins[7] = {8, 9, 10, 11, 12, 13, A0};

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

int bpm = 8; //breaths per min.
int holdDuration = 1000;
int breathDuration = (60000 - ((bpm*2)*holdDuration))/(bpm*2);

    
void loop() {
  int time = 200;

  if (digitalRead(BUTT1_PIN) == LOW) { 
    //One location/motor, gradual 
    for (int i = 0; i < bpm; i++)
    {
      breathSpotG(breathDuration,3);
      delay(holdDuration); //hold
      breathSpotG(breathDuration,5);
      delay(holdDuration); //hold
    }
  }

  if (digitalRead(BUTT2_PIN) == LOW) { 
 //One line, 2 directions up/down, continuous
    for (int i = 0; i < bpm; i++)
    {
      breathInStrokeUp(breathDuration);
      delay(holdDuration); //hold
      breathOutStrokeDown(breathDuration);
      delay(holdDuration); //hold
    }
  }

  if (digitalRead(BUTT3_PIN) == LOW) {
       //One location/motor, once 
    for (int i = 0; i < bpm; i++)
    {
      breathSpotN(breathDuration,3);
      delay(holdDuration); //hold
      breathSpotN(breathDuration,5);
      delay(holdDuration); //hold
    }

  if (digitalRead(BUTT4_PIN) == LOW) {
  
    
   }  
}



    
