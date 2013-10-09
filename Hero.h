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

class Hero : public Object {

	protected:
	void kbd(EventKeyboard *p_keyboard_event);
	void out();
	void moveY(int dy);
	void moveX(int dx);
	void moveXY(EventMouse *me);
	void addLetter(EventCollision *p_e);
	int round;

	public:
	Hero();
	~Hero();
	int eventHandler(Event *p_e);

};

#endif /* HERO_H_ */
