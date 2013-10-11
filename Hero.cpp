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
#include "EventOut.h"
#include "Utility.h"
#include "LevelChange.h"

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

	shieldHitCount = 0;

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
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		addLetter(p_collision_event);
		hit(p_collision_event);
		return 1;
	}

	return 0;

}

// Collisions
void Hero::hit(EventCollision *p_c) {
	ResourceManager &resourcemanager = ResourceManager::getInstance();
	WorldManager &world_manager = WorldManager::getInstance();
	LogManager &logmanager = LogManager::getInstance();

	// Collides with evil characters
	if (p_c -> getObject1() -> getType() == "EvilCharacter") {
		// If player doesn't have a shield up
		shieldHitCount--;
		if(shieldHitCount <= 0) {
			// shield expired
			// Reset normal sprite
			Sprite *p_temp_sprite = resourcemanager.getSprite("hashtag");
			if (!p_temp_sprite) {
					logmanager.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "hashtag");
			}
			else {
				logmanager.writeLog("Hero::Hit(): Setting sprite back to Hashtag\n");
				logmanager.writeLog("Hero::Hit(): Shield Count is %d\n", shieldHitCount);
				setSprite(p_temp_sprite);
				setSpriteSlowdown(0);
			}
		}
		if(shieldHitCount < 0) {
			world_manager.markForDelete(this);
			new LevelChange(1);
		} 		
	}
	else if (p_c -> getObject2() -> getType() == "EvilCharacter") {
		// If player doesn't have a shield up
		shieldHitCount--;
		if(shieldHitCount <= 0) {
			// shield expired
			// Reset normal sprite
			Sprite *p_temp_sprite = resourcemanager.getSprite("hashtag");
			if (!p_temp_sprite) {
					logmanager.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "hashtag");
			}
			else {
				logmanager.writeLog("Hero::Hit(): Setting sprite back to Hashtag\n");
				logmanager.writeLog("Hero::Hit(): Shield Count is %d\n", shieldHitCount);
				setSprite(p_temp_sprite);
				setSpriteSlowdown(0);
			}
		}
		if(shieldHitCount < 0) {
			world_manager.markForDelete(this);
			new LevelChange(1);
		} 		
	} else if(p_c->getObject1()->getType() == "PowerupShield") {
		// Set hit count and change sprite
		shieldHitCount = 2;
		Sprite *p_temp_sprite = resourcemanager.getSprite("hashtag-shield");
		if (!p_temp_sprite) {
				logmanager.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "hashtag-shield");
		}
		else {
			setSprite(p_temp_sprite);
			setSpriteSlowdown(4);
		}
	} else if(p_c->getObject2()->getType() == "PowerupShield") {
		// Set hit count and change sprite
		shieldHitCount = 2;
		Sprite *p_temp_sprite = resourcemanager.getSprite("hashtag-shield");
		if (!p_temp_sprite) {
				logmanager.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "hashtag-shield");
		}
		else {
			setSprite(p_temp_sprite);
			setSpriteSlowdown(4);
		}
	}
}

//Call move (or do nothing) according to key pressed
void Hero::kbd(EventKeyboard *p_keyboard_event) {

	WorldManager &world_manager = WorldManager::getInstance();
	switch(p_keyboard_event->getKey()) {
	case KEY_UP:	//Up arrow
		moveY(-1);
		break;
	case KEY_DOWN:	//Down arrow
		moveY(+1);
		break;
	case KEY_LEFT:	//Left arrow
		moveX(-1);
		break;
	case KEY_RIGHT:	//Right arrow
		moveX(+1);
		break;
	case 'q':
		world_manager.markForDelete(this);
		break;
	}

	return;

}

//Move up or down
void Hero::moveY(int dy) {

	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos(getPosition().getX(), getPosition().getY() + dy);
	//If stays on screen, allow move
	if ((new_pos.getY() > 3) &&
			(new_pos.getY() < worldmanager.getBoundary().getVertical())) {
		worldmanager.moveObject(this, new_pos);
	}

}

//Move left or right
void Hero::moveX(int dx) {

	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos(getPosition().getX() + dx, getPosition().getY());
	//If stays on screen, allow move
	if ((new_pos.getX() > 0) &&
			(new_pos.getX() < worldmanager.getBoundary().getHorizontal())) {
		worldmanager.moveObject(this, new_pos);
	}

}

void Hero::addLetter(EventCollision *p_e) {

	LogManager &logmanager = LogManager::getInstance();
	WorldManager &worldmanager = WorldManager::getInstance();

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
