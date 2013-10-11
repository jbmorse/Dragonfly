/*
 * PowerupShield.cpp
 *
 *   Created: Oct 10, 2013
 *    Author: Tim
 */

// Class include
#include "PowerupShield.h"
// System includes
#include <stdlib.h>
// Engine includes
#include "EventCollision.h"
#include "EventOut.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Utility.h"
#include "WorldManager.h"

PowerupShield::PowerupShield() {
	LogManager &lm = LogManager::getInstance();
	ResourceManager &rm = ResourceManager::getInstance();

	setType("PowerupShield");

	Sprite *p_ts = rm.getSprite("powerup-shield");
	if(!p_ts) {
		lm.writeLog("PowerupShield::PowerupShield(): Warning! Sprite '%s' not found",
			"powerup-shield");
	} else {
		setSprite(p_ts);
		setSpriteSlowdown(10);
	}

	setXVelocity(-0.25);

	setSolidness(SOFT);

	registerInterest(OUT_EVENT);

	WorldManager &wm = WorldManager::getInstance();
	int view_horiz = wm.getView().getHorizontal();
	int view_vert = wm.getView().getHorizontal();
	Position temp_pos(view_horiz + 10,
		random() % (view_vert - 4) + 4);
	temp_pos = viewToWorld(temp_pos);
	setPosition(temp_pos);
}

int PowerupShield::eventHandler(Event *p_e) {
	if(p_e->getType() == OUT_EVENT) {
		WorldManager::getInstance().markForDelete(this);
	} else if(p_e->getType() == COLLISION_EVENT) {
		WorldManager::getInstance().markForDelete(this);
	}
}

