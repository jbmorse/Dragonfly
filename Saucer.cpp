/*
 * Saucer.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#include "EventNuke.h"
#include "EventOut.h"
#include "EventView.h"
#include "Explosion.h"
#include "LogManager.h"
#include "Points.h"
#include "ResourceManager.h"
#include "Saucer.h"
#include "stdlib.h"
#include "WorldManager.h"

Saucer::Saucer() {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup saucer sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("saucer");
	if (!p_temp_sprite) {
		log_manager.writeLog("Saucer::Saucer(): Warning! Sprite '%s' not found", "saucer");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(4);
	}

	//Set object type
	setType("Saucer");

	//Set speed in horizontal direction
	setXVelocity(-0.25);  //1 space every 4 frames

	moveToStart();

	//Register that a nuke can go off
	registerInterest(NUKE_EVENT);

}

Saucer::~Saucer() {

	//Send "view" event with points to interested ViewObjects
	EventView ev(POINTS_STRING, 10, true);
	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.onEvent(&ev);

}

int Saucer::eventHandler(Event *p_e) {

	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == COLLISION_EVENT) {
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	if (p_e->getType() == NUKE_EVENT) {
		//Saucer dies, explode
		Explosion *p_explosion = new Explosion;
		p_explosion -> setPosition(this -> getPosition());
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
		//Need to replace the Saucers
		new Saucer;
	}

    return 0;

}

void Saucer::out() {

	if (getPosition().getX() >= 0) {
		return;
	}

	moveToStart();
	new Saucer;

}

void Saucer::moveToStart() {

	WorldManager &world_manager = WorldManager::getInstance();
	Position new_pos;

	int world_horiz = world_manager.getBoundary().getHorizontal();
	int world_vert = world_manager.getBoundary().getVertical();

	//x is off the right side of screen
	new_pos.setX(world_horiz + random()%world_horiz + 3);

	//y is in the vertical range
	new_pos.setY(random()%(world_vert-4) + 4);

	//If collision, move right slightly until empty space
	ObjectList collision_list = world_manager.isCollision(this, new_pos);
	while (!collision_list.isEmpty()) {
		new_pos.setX(new_pos.getX()+1);
		collision_list = world_manager.isCollision(this, new_pos);
	}

	//Move the saucer
	world_manager.moveObject(this, new_pos);

}

void Saucer::hit(EventCollision *p_c) {

	//If Saucer on Saucer, ignore
	if ((p_c -> getObject1() -> getType() == "Saucer") &&
		(p_c -> getObject2() -> getType() == "Saucer")) {
		return;
	}

	//If Bullet
	if ((p_c -> getObject1() -> getType() == "Bullet") ||
		(p_c -> getObject2() -> getType() == "Bullet")) {
			//Create an explosion
			Explosion *p_explosion = new Explosion;
			p_explosion -> setPosition(this -> getPosition());

			//Saucers appear stay around perpetually
			new Saucer;
	}

	//If hero, mark both objects for destruction
	if (((p_c -> getObject1() -> getType()) == "Hero") ||
		((p_c -> getObject2() -> getType()) == "Hero")) {
			WorldManager &world_manager = WorldManager::getInstance();
			world_manager.markForDelete(p_c -> getObject1());
			world_manager.markForDelete(p_c -> getObject2());
	}
	//If laser, it gets destroyed gloriously
	if (((p_c -> getObject1() -> getType()) == "Laser") ||
		((p_c -> getObject2() -> getType()) == "Laser")) {
		//Create an explosion
		Explosion *p_explosion = new Explosion;
		p_explosion -> setPosition(this -> getPosition());

		//Saucers stay around perpetually
		new Saucer;
	}

}
