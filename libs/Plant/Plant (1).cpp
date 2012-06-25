#include "Arduino.h"
#include "Plant.h"

// round time
const int LIGHT_ROUND = 4500;

Plant::Plant(int health_pins[], int bomb_pin, int def_pin, uint8_t pr_pin){
  photo_pin = pr_pin;
  def_button = def_pin;
  pinMode(def_pin, INPUT);
  bomb_button = bomb_pin;
  pinMode(bomb_pin, INPUT);
  health  = health_pins;
  for (int i=0; i<3; i++){
   pinMode(health_pins[i], OUTPUT);
  }
  move = 0,
  health_status = 0;
  // photoreceptor stuff
  initial_light = analogRead(photo_pin);
  Serial.println("Initial Light: ");
  Serial.println(initial_light);
  was_lit = false;
  curr_lit_time = 0;
  last_read_time = 0;
  light_round_time = 0; 
  // how much higher light reading has to be than the initial read  
  threshold = 20;
};

// doesn't set up output/input pins because that already
// occurred in init for the original plant class (other)
Plant::Plant(const Plant& other){
  def_button = other.def_button;
  bomb_button = other.bomb_button;
	health = other.health;
	health_status = other.health_status;
	move = other.move;
}

// modifies health status and LED
void Plant::incHealth(){
  if (health_status == 3) { return; }
  else {
    digitalWrite(health[health_status], HIGH);
    health_status++; 
  }
}

// modifies health status and LED
void Plant::decHealth(){
  if (health_status == 0) { return; }
  else {
    digitalWrite(health[health_status-1], LOW);
    health_status--; 
  }
}

void Plant::setHealth(int val){
  // verification
  if (val>3) { val=3; }
  else if (val<0) { val=0; }
  // set LEDS
  for (int i=0; i<val; ++i) {
    digitalWrite(health[i], HIGH);
  }
  // turn off LEDs above health value
  for (int j=val; j<3; ++j) {
    digitalWrite(health[j], LOW);
  }
  health_status = val;
}

int Plant::getHealthStatus(){
	return health_status;
}

boolean Plant::checkMove() {
  int bomb_button_state = digitalRead(bomb_button)
  , defend_button_state = digitalRead(def_button);
  if (bomb_button_state == HIGH) {     
    move = 1;
		return true;
  } 
  else if (defend_button_state == HIGH) {     
    move = 2;
	return true;
	}
  return false;
}

int Plant::getFinalMove(){
	return move;
}

void Plant::resetMove() {
	move = 0;
}

void Plant::checkPhoto() {	
	int curr_light = analogRead(photo_pin);
	if (initial_light == 0){
		initial_light = curr_light;
	}	
	Serial.println(curr_light);
	if (curr_light-initial_light >= threshold){
		curr_lit_time = millis();
		if (was_lit == true){
			light_round_time += (curr_lit_time - last_read_time);
			last_read_time = curr_lit_time;
			if (light_round_time > LIGHT_ROUND) {
				incHealth();
				light_round_time = 0;
			}
		}
		else {
			was_lit = true;
			last_read_time = curr_lit_time;
		}
	}
	else {
		was_lit = false;
	}

}