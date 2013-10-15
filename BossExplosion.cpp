/*
 * Explosion.cpp

 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "BossExplosion.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Star.h"
#include "LevelChange.h"

BossExplosion::BossExplosion(Position position) {

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
		setSpriteSlowdown(15);
	}

	//Explode at location
	setPosition(position);

	//Step to disappear
	registerInterest(STEP_EVENT);

	//Set object type
	setType("BossExplosion");
	setSolidness(SPECTRAL);
	setAltitude(4);

	//Set live time as long as sprite length
	time_to_live = getSprite()->getFrameCount() * 15;

}

int BossExplosion::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

void BossExplosion::step() {

	time_to_live--;
	if (time_to_live % 20 == 0) {
		for (int i = 0; i < 30; i++) {
			new Star(this->getPosition());
		}
	}
	if (time_to_live <= 0) {
		for (int i = 0; i < 100; i++) {
			new Star(this->getPosition());
		}
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
		new LevelChange(7);
	}

}
