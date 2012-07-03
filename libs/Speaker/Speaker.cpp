#include "Arduino.h"
#include "pitches.h"
#include "Speaker.h"


Speaker::Speaker(unsigned int pin) {
	speaker_pin = pin;
}

void Speaker::win(unsigned int player){
	int melody[] = {
		NOTE_F4, NOTE_A5,NOTE_C5, NOTE_F6, NOTE_A7,0, NOTE_C7, NOTE_F7};
	
	int noteDurations[] = {
		4, 8, 8, 4,4,4,4,4 };
	
	for (int thisNote = 0; thisNote < 8; thisNote++) {
		
		int noteDuration = 1000/noteDurations[thisNote];
		tone(speaker_pin, melody[thisNote],noteDuration);
		
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		noTone(speaker_pin);
	}
}

void Speaker::tie(){
	int melody[] = {
		NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
	
	int noteDurations[] = {
		4, 8, 8, 4,4,4,4,4 };
	
	for (int thisNote = 0; thisNote < 8; thisNote++) {
		
		int noteDuration = 1000/noteDurations[thisNote];
		tone(speaker_pin, melody[thisNote],noteDuration);
		
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		noTone(speaker_pin);
	}
	
}
void Speaker::attack(){
	
	int melody[] = {
		NOTE_C4, NOTE_B3, NOTE_B3,  NOTE_C4};
	
	int noteDurations[] = {
		2, 8, 8, 2 };
	
	for (int thisNote = 0; thisNote < 4; thisNote++) {
		
		int noteDuration = 1000/noteDurations[thisNote];
		tone(speaker_pin, melody[thisNote],noteDuration);
		
		int pauseBetweenNotes = noteDuration * 1.30;
		// hopefully this delay doesn't screw anything up
		// TODO change code so no delay needed
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(speaker_pin);
	}
}

void Speaker::lvlUp() {
	Serial.println("level up sound");
	int melody[] = {
		NOTE_F4, NOTE_C5 ,0, NOTE_C7};
	
	int noteDurations[] = {
		2, 4, 2, 8 };
	
	for (int thisNote = 0; thisNote < 4; thisNote++) {
		
		int noteDuration = 1000/noteDurations[thisNote];
		tone(speaker_pin, melody[thisNote],noteDuration);
		
		int pauseBetweenNotes = noteDuration * 1.30;
		// hopefully this delay doesn't screw anything up
		// TODO change code so no delay needed
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(speaker_pin);
	}
}

void Speaker::error() {
	int melody[] = {
		NOTE_G3, NOTE_G3};
	
	int noteDurations[] = {
		4, 8};
	
	for (int thisNote = 0; thisNote < 2; thisNote++) {
		
		int noteDuration = 1000/noteDurations[thisNote];
		tone(speaker_pin, melody[thisNote],noteDuration);
		
		int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(speaker_pin);
  }
}

