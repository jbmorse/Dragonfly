/*
 * Laser.cpp
 *
 *  Created on: Sep 5, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "GraphicsManager.h"
#include "Laser.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Laser::Laser(Position hero_pos) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup laser sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("laser");
	if (!p_temp_sprite) {
		log_manager.writeLog("Laser::Laser(): Warning! Sprite '%s' not found", "laser");
	}
	else {
		setSprite(p_temp_sprite);
	}

	//Set object type
	setType("Laser");

	//Step to disappear
	registerInterest(STEP_EVENT);

	//Set starting location, based on the hero's position passed in
	Position pos(hero_pos.getX()+35,  hero_pos.getY());
	setPosition(pos);

	time_to_live = getSprite()->getFrameCount() * 3;

}

int Laser::eventHandler(Event *p_e) {

	if (p_e->getType() == COLLISION_EVENT) {
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}
	if (p_e->getType() == STEP_EVENT) {
			step();
			return 1;
	}

    return 0;

}

//If laser hits saucer, mark saucer for deletion
void Laser::hit(EventCollision *p_c) {

	WorldManager &world_manager = WorldManager::getInstance();
	if ((p_c -> getObject1() -> getType()) == "Saucer") {
		world_manager.markForDelete(p_c->getObject1());
	}
	if ((p_c -> getObject2() -> getType()) == "Saucer") {
	world_manager.markForDelete(p_c->getObject2());
	}

}

void Laser::step() {

	time_to_live--;
	if (time_to_live <= 0) {
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
	}

}
