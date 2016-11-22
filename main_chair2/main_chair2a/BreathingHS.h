/*
 * These methods reperesent deep breathing vibration patterns.
 * Deep breathing involves slow inhale, optional hold, and a slow exhale.
 * Author: Nur Hamdan
 * Date: Non. 19, 2016
 */

#ifndef BreathingHS_h
#define BreathingHS_h
#include "Arduino.h"

/* Continuous vibration: the motor(s) is (are) simply turned on for the end of the breathing duration.
 * Gradual vibration: the motor(s) is repeatedly switched on-off with a certain delay to signify the speed of inhale/exhale for the end of the breathing duration. 
 * Quick vibration: like gradual vibration but the delay is way shorter and does not signify the breathing speed just the direction (in/out).
 */


void swipeFromColToCol(int startCol, int endCol, int startRow, int endRow, int duration, bool gradual); //NOT TESTED
void swipeFromRowToRow(int startRow, int endRow, int startCol, int endCol, int duration); //NOT TESTED

 
/*Parallel rows swipe gradually from mid to edges of back
in <------ ------->
out ------> <------
*/
void breathOutAccordion(int breathDuration);
void breathInAccordion(int breathDuration);

/*Like Accordion but vertical (up/down)*/
void breathInSwipUp(int breathDuration);
void breathOutSwipDown(int breathDuration);

/*One motor vibrates continuously in location on the
upper/lower back*/
void breathInSpot(int breathDuration); 
void breathOutSpot(int breathDuration);

/*One motor vibrates gradually in location on the
upper/lower back*/
void breathInSpotGradual(int breathDuration); //NOT TESTED
void breathOutSpotGradual(int breathDuration); //NOT TESTED

/*Single col vibrates in a quick swipe up/down. The last 
motor in the col vibrates the continuously longest*/
void breathInStrokeUp(int breathDuration);
void breathOutStrokeDown(int breathDuration);

void breathOutSpiral(); //NOT TESTED

void breathOutFlower(); //NOT TESTED

#endif
