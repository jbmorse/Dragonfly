/*
 * Hero.h
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#ifndef HERO_H_
#define HERO_H_

#include "EventKeyboard.h"
#include "Object.h"
#include "EventCollision.h"
#include "EventMouse.h"

#define VELOCITY_CHANGE 0.10
#define MAX_VELOCITY 1.00

/*
 * Most important object! This is the Hashtag Hero (you!).
 * Here can be found a lot of code revolving around moving and
 * collisions and events that progress you through the game.
 * At the end of each level, the hero is made spectral so it can not
 * collide with anything and end the level (twice!).
 * In general hitting anything that is not a Character is a bad idea.
 * Powerups are good! Adds abilities to the hero.
 */
class Hero : public Object {

	protected:
	void kbd(EventKeyboard *p_keyboard_event);
	void hit(EventCollision *p_c);
	void out();
	void moveY(int dy);
	void moveX(int dx);
	void moveXY(EventMouse *me);
	void addLetter(EventCollision *p_e);
	int round;
	int shieldHitCount;

	public:
	Hero();
	~Hero();
	int eventHandler(Event *p_e);

};

#endif /* HERO_H_ */
