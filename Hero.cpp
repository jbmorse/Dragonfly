/*
 * Hero.cpp
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#include "Bullet.h"
#include "EventStep.h"
#include "EventView.h"
#include "Explosion.h"
#include "Hero.h"
#include "GameManager.h"
#include "GameOver.h"
#include "GraphicsManager.h"
#include "Laser.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

Hero::Hero() {

	//Link to ship sprite
	ResourceManager &rm = ResourceManager::getInstance();
	LogManager &lm = LogManager::getInstance();
	Sprite *p_temp_sprite;
	p_temp_sprite = rm.getSprite("ship");
	if (!p_temp_sprite) {
		lm.writeLog("Hero::Hero(): Warning! Sprite '%s' not found", "ship");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(3);		//Third speed animation
		}

	//Player controls hero, so register with keyboard
	registerInterest(KEYBOARD_EVENT);

	//System needs to properly deal with firing
	registerInterest(STEP_EVENT);

	//initialize variables
	fire_slowdown = 15;
	fire_countdown = fire_slowdown;
	laser_charge = 500;

	setType("Hero");
	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(7, world_manager.getBoundary().getVertical()/2);
	setPosition(pos);

}

Hero::~Hero() {

	//Create GameOver object
	GameOver *p_go = new GameOver;
	//Make big explosion
	for (int i=-8; i<=8; i+=5) {
		for (int j=-5; j<=5; j+=3) {
			Position temp_pos = this->getPosition();
			temp_pos.setX(this->getPosition().getX() + i);
			temp_pos.setY(this->getPosition().getY() + j);
			Explosion *p_explosion = new Explosion;
			p_explosion -> setPosition(temp_pos);
		}
	}

}

int Hero::eventHandler(Event *p_e) {

	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = static_cast <EventKeyboard *> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}

	if (p_e->getType() == STEP_EVENT) {
		step();
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
	case (' '):
		fire();
		break;
	case 13:
		laser();
		break;
	case 'q':
		world_manager.markForDelete(this);
		break;
	};

	return;

}

//Move up or down
void Hero::move(int dy) {

	WorldManager &world_manager = WorldManager::getInstance();
	Position new_pos(getPosition().getX(), getPosition().getY() + dy);
	//If stays on screen, allow move
	if ((new_pos.getY() > 3) &&
		(new_pos.getY() < world_manager.getBoundary().getVertical())) {
			world_manager.moveObject(this, new_pos);
	}

}

//Fire a bullet
void Hero::fire() {

	if (fire_countdown > 0) {
		return;
	}

	fire_countdown = fire_slowdown;
	new Bullet(getPosition());

}

//Decrease fire restriction
void Hero::step() {

	fire_countdown--;
	if (fire_countdown < 0) {
		fire_countdown = 0;
	}

	laser_charge++;
	if (laser_charge > 500) {
		laser_charge = 500;
	}

}

void Hero::laser() {

	//Check is laser is charged
	if (laser_charge < 500) {
		return;
	}
	laser_charge = 0;

	//Hero unleashes a powerful laser
	new Laser(getPosition());

}
