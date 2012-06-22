/*
  Game.h - Library for controlling plant
  Created by Jason Schapiro
  Released into the public domain.
*/
#ifndef Game_h
#define Game_h

#include "Arduino.h"
#include "Plant.h"

class Game {
  Plant* p1;
  Plant* p2;
  unsigned long round_start;
  public:
    Game(Plant* p1, Plant* p2);
    void start();
    int setRound();
    void getRoundResult();
		int roundTimeRemaining();
		boolean roundOver();
};

#endif

