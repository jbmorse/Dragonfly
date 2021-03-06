/*
 * FinalBossExplosion.cpp

 *
 *  Created on: Oct 15, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "FinalBossExplosion.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Star.h"
#include "LevelChange.h"
#include "stdlib.h"

FinalBossExplosion::FinalBossExplosion(Position position) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup explosion sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("finalexplosion");
	if (!p_temp_sprite) {
		log_manager.writeLog("FinalBossExplosion::FinalBossExplosion(): Warning! Sprite '%s' not found", "finalexplosion");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(2);
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

int FinalBossExplosion::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

void FinalBossExplosion::step() {

	WorldManager &world_manager = WorldManager::getInstance();

	time_to_live--;
	if (time_to_live % 10 == 0) {
		for (int i = 0; i < 30; i++) {
			Position p(this->getPosition().getX(), random() % (world_manager.getBoundary().getVertical() - 5) + 4);
			new Star(p);
		}
	}
	if (time_to_live <= 0) {
		for (int i = 0; i < 100; i++) {
			new Star(this->getPosition());
		}

		world_manager.markForDelete(this);
		new LevelChange(12);
	}

}
