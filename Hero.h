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
	void kbd(EventKeyboard *p_keyboard_event);
	void move(int dy);

	public:
	Hero();
	~Hero();
	int eventHandler(Event *p_e);
	void draw();

};

#endif /* HERO_H_ */
