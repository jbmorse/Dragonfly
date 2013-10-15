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

/*
 * Boss Explosion is used after the BossSkull is destroyed. It will play through its animation,
 * creating star explosions, and upon its completion it will create a LevelChange to the next level.
 */
class BossExplosion : public Object {

	protected:
	int time_to_live;
	void step();

	public:
	BossExplosion(Position position);
	int eventHandler(Event *p_e);
};

#endif /* BOSSEXPLOSION_H_ */
