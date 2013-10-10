/*
 * PowerupHandler.cpp
 *
 *   Created: Oct 10, 2013
 *     Author: Tim
 */

// Class include
#include "PowerupHandler.h"
// System includes
#include <stdlib.h>
// Engine includes
#include "EventStep.h"
#include "GameManager.h"
#include "PowerupShield.h"
//#include "PowerupWildcard.h"
#include "Utility.h"

PowerupHandler::PowerupHandler() {
	setType("PowerupHandler");
	registerInterest(STEP_EVENT);

	powerupTimeout = 33;//GameManager::getInstance().getFrameTime() * 30;  // 30 secs
	powerupTimeoutCount = powerupTimeout;
}

void PowerupHandler::createPowerup() {
	int randomChance = random() % 10 + 15;
	// 0 - 14: Wildcard
	// 15 - 24: Shield
	if(valueInRange(randomChance, 0, 14)) {

	} else if(valueInRange(randomChance, 15, 24)) {
		new PowerupShield();
	}
}

int PowerupHandler::eventHandler(Event *p_e) {
	if(p_e->getType() == STEP_EVENT) {
		powerupTimeoutCount--;
		if(powerupTimeoutCount <= 0) {
			powerupTimeoutCount = powerupTimeout;
			createPowerup();
		}
		return 1;
	}

	return 0;
}
