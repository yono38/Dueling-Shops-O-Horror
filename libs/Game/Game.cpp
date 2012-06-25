#include "Arduino.h"
#include "Plant.h"
#include "Game.h"

const int ROUND_LENGTH = 5000; // 5 seconds

Game::Game(Plant* P_1, Plant* P_2) {
	p1 = P_1;
	p2 = P_2;
	round_start = 0;
}

void Game::start(){
}

int Game::setRound(){
  round_start = millis();
  return round_start;
};

int Game::roundTimeRemaining(){
	return ROUND_LENGTH - (millis()-round_start);
}

boolean Game::roundOver(){
	if (roundTimeRemaining() <= 0){
		return true;
	} else {
		return false;
	}
}

// 1 = bomb, 2 = defend, 0 = no move
String Game::getRoundResult(){
	int p1mv = p1->getFinalMove()
		, p2mv = p2->getFinalMove();
	// P1 & P2 no move
	if (p1mv == 0 && p2mv == 0){
		Serial.println("P1 & P2 no move");
	}
  // P1 no move, P2 defend
	else if (p1mv == 0 && p2mv == 2 ) {
		Serial.println("P1 no move, P2 defend");
	}
	// P1 no move, P2 bomb
	else if (p1mv == 0 && p2mv == 1 ) {
		p1->decHealth();
		Serial.println("P1 no move, P2 bomb");
	}
	// P2 no move, P1 defend
	else if (p2mv == 0 && p1mv ==  2 ) {
		Serial.println("P2 no move, P1 defend");
	}
	// P2 no move, P1 bomb
	else if (p2mv == 0 && p1mv == 1 ) {
		p1->decHealth();
		Serial.println("P2 no move, P1 bomb");
	}
	// P1 & P2 bomb
	else if (p1mv == 1 && p2mv == 1 ) {
		p1->decHealth();
		p2->decHealth();
		Serial.println("P1 & P2 bomb");
	}
	// P1 bomb, P2 defend
	else if (p1mv == 1 && p2mv == 2 ) {
		p1->decHealth();
		Serial.println(" P1 bomb, P2 defend");
	}
	// P2 bomb, P1 defend
	else if (p2mv == 1 && p1mv == 2 ) {
		p2->decHealth();
		Serial.println("P2 bomb, P1 defend");
	}
	// P1 & P2 defend
	else if (p1mv == 2 && p2mv == 2 ) {
		Serial.println("P1 & P2 defend");
	}
	else {
		Serial.print('P1 Move: ');
		Serial.println(p1mv);
		Serial.print('P2 Move: ');
		Serial.println(p2mv);
	}
	// check for endgame
  int p1_health = p1->getHealthStatus()
		, p2_health = p2->getHealthStatus();
	if (p1_health == 0 && p2_health == 0){
		return "Tie";
	}	else if (p1_health == 0 || p2_health == 0){
		return "Win";
	} 
	return "Continue";
	//else if () {
		// p1 win sequence
//	}
	// new round, reset moves
	p1->resetMove();
	p2->resetMove();
}


