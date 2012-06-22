/*
  Plant.h - Library for controlling plant
  Created by Jason Schapiro
  Released into the public domain.
*/
#ifndef Plant_h
#define Plant_h

#include "Arduino.h"

class Plant {
 int* health;
 int health_status
 , bomb_button
 , def_button
 , move;
 public:
  Plant(int health_pins[], int bomb_pin, int def_pin); 
  Plant(const Plant& other);
  void incHealth();
  void decHealth();
  void setHealth(int val);
	int getHealthStatus();
  boolean checkMove();
	int getFinalMove();
	void resetMove();
};

#endif

