/*
 * SafeBox.cpp

 *
 *  Created on: Oct 14, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "SafeBox.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Star.h"
#include "LevelChange.h"

SafeBox::SafeBox(Position position) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup explosion sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("safebox");
	if (!p_temp_sprite) {
		log_manager.writeLog("SafeBox::SafeBox(): Warning! Sprite '%s' not found", "safebox");
	}
	else {
		setSprite(p_temp_sprite);
	}

	setPosition(position);

	//Step to disappear
	registerInterest(STEP_EVENT);

	//Set object type
	setType("SafeBox");
	setSolidness(SOFT);
	setAltitude(0);
	time_to_live = 1;

}

int SafeBox::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

void SafeBox::step() {

	WorldManager &world_manager = WorldManager::getInstance();
	if (time_to_live <= 0) {
		world_manager.markForDelete(this);
	}
	time_to_live--;

}
