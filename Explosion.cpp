/*
 * Explosion.cpp

 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "Explosion.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Explosion::Explosion() {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup explosion sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("explosion");
	if (!p_temp_sprite) {
		log_manager.writeLog("Explosion::Explosion(): Warning! Sprite '%s' not found", "explosion");
	}
	else {
		setSprite(p_temp_sprite);
	}

	//Step to disappear
	registerInterest(STEP_EVENT);

	//Set object type
	setType("Explosion");
	setSolidness(SPECTRAL);

	//Set live time as long as sprite length
	time_to_live = getSprite()->getFrameCount();

}

int Explosion::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

void Explosion::step() {

	time_to_live--;
	if (time_to_live <= 0) {
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
	}

}
