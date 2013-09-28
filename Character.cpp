/*
 * Character.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: Josh
 */

#include "EventOut.h"
#include "LogManager.h"
#include "Character.h"
#include "stdlib.h"
#include "WorldManager.h"
#include "GraphicsManager.h"
#include "EventStep.h"
#include "EventRefresh.h"

Character::Character() {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();

	//Set object type
	setType("Character");

	setAltitude(1);

	//Set speed in horizontal direction
	setXVelocity(-0.40);  //1 space every 4 frames

	moveToStart();

	//Register for step and refresh
	registerInterest(STEP_EVENT);
	registerInterest(REFRESH_EVENT);

	charnum = rand() % 26;
	drawchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

}

Character::~Character() {

}

int Character::eventHandler(Event *p_e) {

	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == COLLISION_EVENT) {
		LogManager &logmanager = LogManager::getInstance();
		logmanager.writeLog("Character::eventHandler: received Collision event!\n");
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	if (p_e->getType() == STEP_EVENT) {
		stepcount++;
		if (stepcount > 200) {
			stepcount = 0;
			charnum = rand() % 26;
		}
	}

	if (p_e->getType() == REFRESH_EVENT) {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.markForDelete(this);
	}

    return 0;

}

void Character::out() {

	if (getPosition().getX() >= 0) {
		return;
	}

	moveToStart();

}

void Character::moveToStart() {

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos;

	int world_horiz = graphicsmanager.getHorizontal();
	int world_vert = graphicsmanager.getVertical();

	//x is off the right side of screen
	new_pos.setX(world_horiz + random()%world_horiz + 3);

	//y is in the vertical range
	new_pos.setY(random()%(world_vert-4) + 4);

	//If collision, move right slightly until empty space
	ObjectList collision_list = worldmanager.isCollision(this, new_pos);
	while (!collision_list.isEmpty()) {
		new_pos.setX(new_pos.getX()+1);
		collision_list = worldmanager.isCollision(this, new_pos);
	}

	//Move the character
	worldmanager.moveObject(this, new_pos);

}

void Character::hit(EventCollision *p_c) {

	//If Character on Character, ignore
	if ((p_c -> getObject1() -> getType() == "Character") &&
		(p_c -> getObject2() -> getType() == "Character")) {
		return;
	}

	WorldManager &world_manager = WorldManager::getInstance();
	//If hero, mark for destruction
	if (p_c -> getObject1() -> getType() == "Hero") {
		world_manager.markForDelete(p_c -> getObject2());
	}
	else if (p_c -> getObject2() -> getType() == "Hero") {
		world_manager.markForDelete(p_c -> getObject1());
	}

}

void Character::draw() {

	int i = rand() % 26;
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawCh(this->getPosition(), drawchar[charnum], COLOR_WHITE);

}

char Character::getChar() {

	return drawchar[charnum];

}
