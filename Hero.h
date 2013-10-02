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

class Hero : public Object {

	protected:
	int fire_slowdown;
	int fire_countdown;
	int laser_charge;
	void kbd(EventKeyboard *p_keyboard_event);
	void move(int dy);
	void fire();
	void step();
	void laser();

	public:
	Hero();
	~Hero();
	int eventHandler(Event *p_e);

};

#endif /* HERO_H_ */
