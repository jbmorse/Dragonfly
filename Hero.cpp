/*
 * Hero.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "Hero.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "WorldManager.h"

Hero::Hero() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Hero::Hero(): Made the hero!\n");

	//Player controls hero, so register with keyboard
	registerInterest(KEYBOARD_EVENT);

	setType("Hero");
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	Position pos(7, graphicsmanager.getVertical()/2);
	setPosition(pos);

}

Hero::~Hero() {

}

int Hero::eventHandler(Event *p_e) {

	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}

	return 0;

}

//Call move (or do nothing) according to key pressed
void Hero::kbd(EventKeyboard *p_keyboard_event) {

	WorldManager &world_manager = WorldManager::getInstance();
	switch(p_keyboard_event->getKey()) {
	case KEY_UP:	//Up arrow
		move(-1);
		break;
	case KEY_DOWN:	//Down arrow
		move(+1);
		break;
	case 'q':
		world_manager.markForDelete(this);
		break;
	};

	return;

}

//Move up or down
void Hero::move(int dy) {

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos(getPosition().getX(), getPosition().getY() + dy);
	//If stays on screen, allow move
	if ((new_pos.getY() > 3) &&
		(new_pos.getY() < graphicsmanager.getVertical())) {
			worldmanager.moveObject(this, new_pos);
	}

}

void Hero::draw() {

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawCh(this->getPosition(), '#', COLOR_WHITE);

}
