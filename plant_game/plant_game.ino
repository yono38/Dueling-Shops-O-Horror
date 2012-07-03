/* Dueling Shops 'O Horror
 * Code by Jason Schapiro
 * Design by Sarah Schoemann
 */

#include <Plant.h>
#include <Game.h>
#include <pitches.h>
#include <Speaker.h>

  // Set Up Plant Hardware Configuration
int p1_health_pins[] = { 6, 7, 8 }

, p1_def_btn = 2, p1_bmb_btn = 3;
uint8_t p1_pr_pin = A0;

int p2_health_pins[] = { 11, 10, 9 }

, p2_def_btn = 5, p2_bmb_btn = 4;
uint8_t p2_pr_pin = A1;


Plant plant1(p1_health_pins, p1_bmb_btn, p1_def_btn, p1_pr_pin);
Plant plant2(p2_health_pins, p2_bmb_btn, p2_def_btn, p2_pr_pin);

unsigned int speaker_pin = 12;

  // Set Up Game
Game my_game(&plant1, &plant2);
Speaker sound(speaker_pin);
boolean round_in_motion;
boolean ending_alert;
int round_led = 19;

void setup()
{
    round_in_motion = false;
    ending_alert = false;
//    plant1.setHealth(3);
//  TODO comment this when sensor used
//    plant2.setHealth(3);
    Serial.begin(9600);
    Serial.println("test");
    pinMode(round_led, OUTPUT);
    digitalWrite(round_led, LOW);
}

void loop()
{
    boolean lvl_up_p1 = plant1.checkPhoto();
  boolean lvl_up_p2 =	plant2.checkPhoto();
//    Serial.println(lvl_up_p1);
//    if (lvl_up_p1){
    if (lvl_up_p1 || lvl_up_p2){
      sound.lvlUp();
    } 
    if (my_game.start()){
		boolean p1_moved = plant1.checkMove()
		, p2_moved = plant2.checkMove();

		if ((p1_moved && plant1.getCurrentMove() == 0) || (p2_moved && plant2.getCurrentMove() == 0)){
			sound.error();
		}
		if (!round_in_motion && (p1_moved || p2_moved)) {
		Serial.println("Round started!");
		Serial.println(millis());
		my_game.setRound();
		round_in_motion = true;
		digitalWrite(round_led, HIGH);
		} else if (round_in_motion) {
		if (my_game.roundOver()) {
			// reset values
			round_in_motion = false;
			ending_alert = false;
			// debug info
			Serial.println("Round ended!");
			digitalWrite(round_led, LOW);
			sound.attack();
	/*		Serial.println(millis());
			Serial.println("P1 Move: ");
			Serial.println(plant1.getFinalMove());
			Serial.println("P2 Move: ");
			Serial.println(plant2.getFinalMove()); */
			// actual code that does the work
			String round_result = my_game.getRoundResult();
			if (round_result == "Win") {
			sound.win(1);
			return;
			} else if (round_result == "Tie") {
			sound.tie();
			return;
			}
		} else if (ending_alert) {
			alertBlink();
		} else if (!ending_alert && my_game.roundTimeRemaining() < 1000) {
			alertBlink();
			ending_alert = true;
		}
		}
	}
}

void alertBlink()
{
    // 1000 off, 900 on, 800 off, 700 on, 600 off
    // 5 on, 4 off, 3 on, 2 off, 1 on, 0 off
    unsigned int remaining = my_game.roundTimeRemaining();
    if (remaining < 100) {
	digitalWrite(round_led, HIGH);
    } else if (remaining < 200) {
	digitalWrite(round_led, LOW);
    } else if (remaining < 300) {
	digitalWrite(round_led, HIGH);
    } else if (remaining < 400) {
	digitalWrite(round_led, LOW);
    } else if (remaining < 500) {
	digitalWrite(round_led, HIGH);
    } else if (remaining < 600) {
	digitalWrite(round_led, LOW);
    } else if (remaining < 700) {
	digitalWrite(round_led, HIGH);
    } else if (remaining < 800) {
	digitalWrite(round_led, LOW);
    } else if (remaining < 900) {
	digitalWrite(round_led, HIGH);
    } else if (remaining < 1000) {
	digitalWrite(round_led, LOW);
    } else {
	digitalWrite(round_led, HIGH);
    }
}


