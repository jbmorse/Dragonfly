/*
 * Bullet.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "EventCollision.h"
#include "Object.h"

class Bullet : public Object {

	protected:
	void out();
	void hit(EventCollision *p_c);

	public:
	Bullet(Position hero_pos);
	int eventHandler(Event *p_e);

};

#endif /* BULLET_H_ */
