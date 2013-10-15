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
 *
 */
class BossFinal : public Object {

	protected:
	void moveY(int dy);
	void moveX(int dx);
	void attack();
	void hit(EventCollision *p_c);
	int attack_countup;
	int health;

	public:
	BossFinal();
	~BossFinal();
	int eventHandler(Event *p_e);

};


#endif /* BOSSFINAL_H_ */
