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
 uint8_t photo_pin;
 boolean was_lit;
 unsigned int initial_light;
 unsigned long curr_lit_time;
 unsigned long last_read_time;
 unsigned int light_round_time;
 unsigned int threshold;
 public:
  Plant(int health_pins[], int bomb_pin, int def_pin, uint8_t pr_pin); 
  Plant(const Plant& other);
  void incHealth();
  void decHealth();
  void setHealth(int val);
  int getHealthStatus();
  boolean checkMove();
  int getFinalMove();
  void resetMove();
  void checkPhoto();
};

#endif

