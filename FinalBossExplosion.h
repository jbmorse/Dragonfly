/*
 * FinalBossExplosion.h
 *
 *  Created on: Oct 12, 2013
 *      Author: Josh
 */

#ifndef FINALBOSSEXPLOSION_H_
#define FINALBOSSEXPLOSION_H_

#include "Object.h"
#include "ResourceManager.h"

/*
 * Boss Explosion is used after the FinalSkull is destroyed. It will play through its animation,
 * creating star explosions, and upon its completion it will create a LevelChange to the start of game.
 */
class FinalBossExplosion : public Object {

	protected:
	int time_to_live;
	void step();

	public:
	FinalBossExplosion(Position position);
	int eventHandler(Event *p_e);
};

#endif /* FINALBOSSEXPLOSION_H_ */
