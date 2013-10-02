/*
 * Bullet.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "Bullet.h"
#include "EventOut.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Bullet::Bullet(Position hero_pos) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup bullet sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("bullet");
	if (!p_temp_sprite) {
		log_manager.writeLog("Bullet::Bullet(): Warning! Sprite '%s' not found", "bullet");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(5);
	}

	//Set object type
	setType("Bullet");

	//Set speed in horizontal direction
	setXVelocity(1);  //1 space every 5 frames

	//Set starting location, based on the hero's position passed in
	Position pos(hero_pos.getX()+3,  hero_pos.getY());
	setPosition(pos);

}

int Bullet::eventHandler(Event *p_e) {

	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}
	if (p_e->getType() == COLLISION_EVENT) {
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

    return 0;

}

//If bullet moves outside world, destroy itself
void Bullet::out() {

	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.markForDelete(this);

}

//If bullet hits saucer, mark saucer and bullet for deletion
void Bullet::hit(EventCollision *p_c) {

	WorldManager &world_manager = WorldManager::getInstance();
	if (p_c -> getObject1() -> getType() != "Laser") {
		world_manager.markForDelete(p_c->getObject1());
	}
	if (p_c -> getObject2() -> getType() != "Laser") {
	world_manager.markForDelete(p_c->getObject2());
	}

}
