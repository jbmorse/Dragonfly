/*
 * PowerupWildcard.h
 *
 *   Created: Oct 14, 2013
 *    Author: Tim
 */

#ifndef _POWERUPWILDCARD_H_
#define _POWERUPWILDCARD_H_

// Engine includes
#include "Event.h"
#include "Object.h"

/*
 * This wildcard powerup can be picked up by the hero.
 * It will fill in the next needed character for the
 * needed string, or do damage to the boss.
 */
class PowerupWildcard : public Object {

public:
	PowerupWildcard();
	int eventHandler(Event *p_e);
	void draw();
};

#endif // _POWERUPWILDCARD_H_
