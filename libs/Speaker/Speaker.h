/*
 Speaker.h - Library for controlling plant game speakers
 Created by Jason Schapiro
 Derived from the toneMelody code (http://arduino.cc/en/Tutorial/Tone)
 Released into the public domain.
 */
#ifndef Speaker_h
#define Speaker_h

#include "Arduino.h" 
#include "pitches.h"


class Speaker {
	int speaker_pin;
public:
	Speaker(unsigned int pin);
	void win(unsigned int player);
	void tie();
	void attack();
	void lvlUp();
	void error();
};

#endif