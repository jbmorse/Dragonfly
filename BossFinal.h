/*
 * BossFinal.h
 *
 *  Created on: Oct 14, 2013
 *      Author: Josh
 */

#ifndef BOSSFINAL_H_
#define BOSSFINAL_H_

#include "EventKeyboard.h"
#include "Object.h"
#include "EventCollision.h"
#include "EventMouse.h"

/*
 * FINAL BOSS has 3 modes of attack, once dead the game ends in victory
 */
class BossFinal : public Object {

	protected:
	void moveY(int dy);
	void moveX(int dx);
	void attack1();
	void attack2();
	void attack3();
	void laser();
	void hit(EventCollision *p_c);
	int attack_countup;
	int health;
	int chartimer;

	public:
	BossFinal();
	~BossFinal();
	int eventHandler(Event *p_e);

};


#endif /* BOSSFINAL_H_ */
