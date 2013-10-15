/*
 * PowerupShield.h
 *
 *   Created: Oct 10, 2013
 *    Author: Tim
 */

#ifndef _POWERUPSHIELD_H_
#define _POWERUPSHIELD_H_

// Engine includes
#include "Event.h"
#include "Object.h"

/*
 * This shield powerup can be grabbed by the hero.
 * It will protect the hero from 2 hits.
 */
class PowerupShield : public Object {

public:
	PowerupShield();
	int eventHandler(Event *p_e);
};

#endif // _POWERUPSHIELD_H_
