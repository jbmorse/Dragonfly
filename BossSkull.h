/*
 * BossSkull.h
 *
 *  Created on: Oct 8, 2013
 *      Author: Josh
 */

#ifndef BOSSSKULL_H_
#define BOSSSKULL_H_

#include "EventKeyboard.h"
#include "Object.h"
#include "EventCollision.h"
#include "EventMouse.h"

class BossSkull : public Object {

	protected:
	void moveY(int dy);
	void moveX(int dx);
	void attack();
	int attack_countup;
	int health;
	int move_countdown;

	public:
	BossSkull();
	~BossSkull();
	int eventHandler(Event *p_e);

};


#endif /* BOSSSKULL_H_ */
