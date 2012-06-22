/* Dueling Shops 'O Horror
 * Code by Jason Schapiro
 * Design by Sarah Schoemann
 */

#include <Plant.h>
#include <Game.h>

  // Set Up Plant Hardware Configuration
  int p1_health_pins[] = {6,7,8}
  ,	p1_def_btn = 2
  , p1_bmb_btn = 3;
	
   int	p2_health_pins[] = {9,10,11}
  , p2_def_btn = 5
  , p2_bmb_btn = 4;

  Plant plant1(p1_health_pins, p1_bmb_btn, p1_def_btn);
  Plant plant2(p2_health_pins, p2_bmb_btn, p2_def_btn);

  // Set Up Game
  Game my_game(&plant1, &plant2);
  boolean round_in_motion;

void setup(){
  round_in_motion = false;
  plant1.setHealth(3);
  plant2.setHealth(3);
  Serial.begin(9600);
  Serial.println("test");
}

void loop(){ 
	boolean p1_moved = plant1.checkMove()
	 , p2_moved = plant2.checkMove();	
	if (p1_moved){
          Serial.println(plant1.getFinalMove());
          // remove this later
          delay(20);
        }
        if (p2_moved){
          Serial.println(plant2.getFinalMove());
          //remove this later
          delay(20);
        }  
	if (!round_in_motion && (p1_moved || p2_moved)){
                Serial.println("Round started!");
                Serial.println(millis());
		my_game.setRound();
		round_in_motion = true;
	}
	else if (round_in_motion){
		if (my_game.roundOver()){
  	           round_in_motion = false;
                   Serial.println("Round ended!");
                   Serial.println(millis());
		   Serial.println("P1 Move: ");
		   Serial.println(plant1.getFinalMove());
		   Serial.println("P2 Move: ");
		   Serial.println(plant2.getFinalMove());
                   my_game.getRoundResult();

		}
		// TODO later put in led seq for time almost up
	}	
}
