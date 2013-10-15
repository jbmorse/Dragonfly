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

	//Set object type
	setType("Character");

	setAltitude(2);
	setSolidness(SOFT);

	moveToStart();

	//Register for step and refresh
	registerInterest(REFRESH_EVENT);

	int charnum = random() % 26;
	string drawchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	chartype = drawchar[charnum];

}

Character::Character(char newchar) {

	//Set object type
	setType("Character");

	setAltitude(2);

	moveToStart();

	//Register for step and refresh
	registerInterest(REFRESH_EVENT);

	chartype = newchar;

}

Character::Character(bool spectral) {

	//Set object type
	setType("Character");

	setAltitude(2);
	if (spectral) {
		setSolidness(SPECTRAL);
	}
	else {
		setSolidness(SOFT);
	}

	moveToStart();

	//Register for step and refresh
	registerInterest(REFRESH_EVENT);

	int charnum = random() % 26;
	string drawchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	chartype = drawchar[charnum];

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
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

    return 0;

}

void Character::out() {

	if (getPosition().getX() >= 0) {
		return;
	}

	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.markForDelete(this);
	//setXVelocity(getXVelocity() * -1);
	//setYVelocity(getYVelocity() * -1);

//	moveToStart();

}

void Character::moveToStart() {

	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos;

	int world_horiz = worldmanager.getBoundary().getHorizontal();
	int world_vert = worldmanager.getBoundary().getVertical();

	//x is off the right side of screen
	new_pos.setX(random()%(world_horiz-4) + 2);

	//y is in the vertical range
	new_pos.setY(random()%(world_vert-6) + 5);

	//If collision, move right slightly until empty space
	ObjectList collision_list = worldmanager.isCollision(this, new_pos);
	while (!collision_list.isEmpty()) {
		new_pos.setX(random()%(world_horiz-4) + 2);
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

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawCh(this->getPosition(), chartype, COLOR_WHITE);

}

char Character::getChar() {

	return chartype;

}

void Character::setChar(char newchar) {

	chartype = newchar;

}
