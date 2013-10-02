/*
 * Laser.h
 *
 *  Created on: Sep 5, 2013
 *      Author: Josh
 */

#ifndef LASER_H_
#define LASER_H_

#include "EventCollision.h"
#include "Object.h"

class Laser : public Object {

	protected:
	int time_to_live;
	void hit(EventCollision *p_c);
	void step();

	public:
	Laser(Position hero_pos);
	int eventHandler(Event *p_e);

};


#endif /* LASER_H_ */
