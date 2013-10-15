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

/*
 * BossSkull is the boss for level 5. He will fire evilcharacters at the player.
 * His movement pattern is moving up and down randomly.
 * Occasionally he will fire good characters that can be picked up that deals damage.
 * After 3 good characters are picked up, the BossSkull will die, creating BossExplosion.
 * His sprite will change upon each damage he takes.
 */
class BossSkull : public Object {

	protected:
	void moveY(int dy);
	void moveX(int dx);
	void attack();
	void hit(EventCollision *p_c);
	int attack_countup;
	int health;
	int move_countdown;

	public:
	BossSkull();
	~BossSkull();
	int eventHandler(Event *p_e);

};


#endif /* BOSSSKULL_H_ */
