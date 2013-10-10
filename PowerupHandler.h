/*
 * PowerupHandler.h
 *
 *  Created: Oct 10, 2013
 *    Author: Tim
 */

#ifndef _POWERUPHANDLER_H_
#define _POWERUPHANDLER_H_

// Engine includes
#include "Event.h"
#include "Object.h"

class PowerupHandler : public Object {

private:
	void createPowerup();
	int powerupTimeout;
	int powerupTimeoutCount;

public:
	PowerupHandler();
	int eventHandler(Event *p_e);
};

#endif // _POWERUPHANDLER_H_
