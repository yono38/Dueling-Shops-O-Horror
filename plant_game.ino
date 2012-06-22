/* Dueling Shops 'O Horror
 * Code by Jason Schapiro
 * Design by Sarah Schoemann
 */

#include <Plant.h>
#include <Game.h>

  // Set Up Plant Hardware Configuration
  int p1_health_pins[] = {2,3,4}
  ,	p1_def_btn = 5
  , p1_bmb_btn = 6;
	
   int	p2_health_pins[] = {7,8,9}
  , p2_def_btn = 10
  , p2_bmb_btn = 11;

  Plant plant1(p1_health_pins, p1_def_btn, p1_bmb_btn);
  Plant plant2(p2_health_pins, p2_def_btn, p2_bmb_btn);

  // Set Up Game
  Game my_game(&plant1, &plant2);
  boolean round_in_motion;

void setup(){
  round_in_motion = false;
  plant1.setHealth(3);
  plant2.setHealth(3);
}

void loop(){ 
	boolean p1_moved = plant1.checkMove()
	 , p2_moved = plant2.checkMove();	
	// 
	if (!round_in_motion && (p1_moved || p2_moved)){
		my_game.setRound();
		round_in_motion = true;
	}
	else if (round_in_motion){
		if (my_game.roundOver()){
			my_game.getRoundResult();
			round_in_motion = false;
		}
		// TODO later put in led seq for time almost up
	}	
}
