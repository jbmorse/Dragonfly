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
#include <string>
#include <iostream>

using namespace std;
using std::string;

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

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Hero::eventHandler: Hero got an event! \n");

	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}

	return 0;

}

//Call move (or do nothing) according to key pressed
void Hero::kbd(EventKeyboard *p_keyboard_event) {

	LogManager &logmanager = LogManager::getInstance();

	WorldManager &world_manager = WorldManager::getInstance();
	switch(p_keyboard_event->getKey()) {
	case KEY_UP:	//Up arrow
		logmanager.writeLog("Hero:kbd: received UP\n");
		move(-1);
		break;
	case KEY_DOWN:	//Down arrow
		logmanager.writeLog("Hero:kbd: received UP\n");
		move(+1);
		break;
	}

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
