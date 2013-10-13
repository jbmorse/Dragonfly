/*
 * BossExplosion.h
 *
 *  Created on: Oct 12, 2013
 *      Author: Josh
 */

#ifndef BOSSEXPLOSION_H_
#define BOSSEXPLOSION_H_

#include "Object.h"
#include "ResourceManager.h"

class BossExplosion : public Object {

	protected:
	int time_to_live;
	void step();

	public:
	BossExplosion(Position position);
	int eventHandler(Event *p_e);
};

#endif /* BOSSEXPLOSION_H_ */
