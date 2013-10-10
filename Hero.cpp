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
#include "EventCollision.h"
#include "EventRefresh.h"
#include "Character.h"
#include "EventMouse.h"
#include <string>
#include <iostream>
#include "time.h"
#include <cstdlib>
#include <math.h>
#include "ResourceManager.h"
#include "EventCapturedLetter.h"
#include "GameOver.h"
#include "EventOut.h"
#include "Utility.h"

using namespace std;
using std::string;

Hero::Hero() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Hero::Hero(): Made the hero!\n");
	round = 1;

	//Player controls hero, so register with keyboard/mouse
	registerInterest(KEYBOARD_EVENT);

	ResourceManager &resourcemanager = ResourceManager::getInstance();
	setType("Hero");

	//Keep hero centered
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.setViewFollowing(this);

	Sprite *p_temp_sprite = resourcemanager.getSprite("hashtag");
	if (!p_temp_sprite) {
			logmanager.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "hashtag");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(0);
	}

	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(7, world_manager.getBoundary().getVertical()/2);
	setPosition(pos);
	setAltitude(2);

}

Hero::~Hero() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Hero::~Hero: Hero is deleted! \n");

}

int Hero::eventHandler(Event *p_e) {

	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	if (p_e->getType() == COLLISION_EVENT) {
		LogManager &logmanager = LogManager::getInstance();
		logmanager.writeLog("Hero::eventHandler: Hero got a collision event! \n");
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		addLetter(p_collision_event);
		return 1;
	}
	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}

	return 0;

}

//Hero went out of bounds
void Hero::out() {

	WorldManager &world_manager = WorldManager::getInstance();
	Position pos = worldToView(getPosition());
	if (pos.getX() < 0) {
		setXVelocity(0);
		pos.setX(0);
	}
	if (pos.getX() > world_manager.getView().getHorizontal()) {
		setXVelocity(0);
		pos.setX(world_manager.getView().getHorizontal() - 1);
	}
	if (pos.getY() < 0) {
		setYVelocity(0);
		pos.setY(0);
	}
	if (pos.getY() > world_manager.getView().getVertical()) {
		setYVelocity(0);
		pos.setY(world_manager.getView().getVertical() - 1);
	}

	setPosition(viewToWorld(pos));

}

//Call move (or do nothing) according to key pressed
void Hero::kbd(EventKeyboard *p_keyboard_event) {

	WorldManager &world_manager = WorldManager::getInstance();
	switch(p_keyboard_event->getKey()) {
	case KEY_UP:	//Up arrow
		setYVelocity(max(getYVelocity() - VELOCITY_CHANGE, (-1) *  MAX_VELOCITY));
		break;
	case KEY_DOWN:	//Down arrow
		setYVelocity(min(getYVelocity() + VELOCITY_CHANGE, MAX_VELOCITY));
		break;
	case KEY_LEFT:	//Left arrow
		setXVelocity(max(getXVelocity() - VELOCITY_CHANGE, (-1) * MAX_VELOCITY));
		break;
	case KEY_RIGHT:	//Right arrow
		setXVelocity(min(getXVelocity() + VELOCITY_CHANGE, MAX_VELOCITY));
		break;
	case 'q':
		world_manager.markForDelete(this);
		break;
	}

	return;

}

void Hero::addLetter(EventCollision *p_e) {

	LogManager &logmanager = LogManager::getInstance();
	WorldManager &worldmanager = WorldManager::getInstance();
	logmanager.writeLog("Hero::addLetter: received Collision event! Adding letter to hashtag\n");

	Character *character;
	if (p_e->getObject1()->getType() == "Character") {
		character = static_cast <Character *> (p_e->getObject1());
		EventCapturedLetter ecl;
		ecl.setCapturedLetter(character->getChar());
		worldmanager.onEvent(&ecl);
	}
	else if (p_e->getObject2()->getType() == "Character") {
		character = static_cast <Character *> (p_e->getObject2());
		EventCapturedLetter ecl;
		ecl.setCapturedLetter(character->getChar());
		worldmanager.onEvent(&ecl);
	}

}
