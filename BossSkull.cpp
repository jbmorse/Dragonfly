/*
 * BossSkull.cpp
 *
 *  Created on: Oct 8, 2013
 *      Author: Josh
 */

#include "BossSkull.h"
#include "EventStep.h"
#include "Stdlib.h"
#include "EventCollision.h"
#include "stdlib.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EvilCharacter.h"
#include "LevelChange.h"
#include "EventCapturedLetter.h"
#include "Character.h"
#include "BossExplosion.h"

using namespace std;
using std::string;

BossSkull::BossSkull() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("BossSkull::BossSkull: Made the Boss!\n");

	ResourceManager &resourcemanager = ResourceManager::getInstance();
	setType("BossSkull");

	Sprite *p_temp_sprite = resourcemanager.getSprite("skull1");
	if (!p_temp_sprite) {
			logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "skull1");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(4);
	}

	//Step to disappear
	registerInterest(STEP_EVENT);
	registerInterest(CAPTURED_LETTER_EVENT);

	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(((world_manager.getBoundary().getHorizontal()*5)/6), world_manager.getBoundary().getVertical()/2);
	setPosition(pos);
	setAltitude(2);

	health = 3;
	attack_countup = 0;
	move_countdown = 4;

}

BossSkull::~BossSkull() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("I died BOSSSKULL\n");

}

int BossSkull::eventHandler(Event *p_e) {

	WorldManager &worldmanager = WorldManager::getInstance();
	LogManager &logmanager = LogManager::getInstance();
	ResourceManager &resourcemanager = ResourceManager::getInstance();

	if (p_e->getType() == COLLISION_EVENT) {
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	if (p_e->getType() == STEP_EVENT) {
		attack_countup++;
		move_countdown--;
		if (move_countdown <= 0) {
			move_countdown = 4;
			int move = random() % 3 - 1;
			moveY(move);
		}
		else if ((random() % 200 + attack_countup) > 200) {
			attack();
			attack_countup = 0;
		}
		return 1;
	}
	if (p_e->getType() == CAPTURED_LETTER_EVENT) {
		health--;
		//If health 2, set next sprite
		if (health == 2) {
			Sprite *p_temp_sprite = resourcemanager.getSprite("skull2");
			if (!p_temp_sprite) {
				logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "skull2");
			}
			else {
				setSprite(p_temp_sprite);
				setSpriteSlowdown(4);
			}
		}
		//If health 1, set to almost dead sprite
		if (health == 1) {
			Sprite *p_temp_sprite = resourcemanager.getSprite("skull3");
			if (!p_temp_sprite) {
				logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "skull3");
			}
			else {
				setSprite(p_temp_sprite);
				setSpriteSlowdown(4);
			}
		}
		//If health 0, dead and explode
		if (health <= 0) {
			new BossExplosion(this->getPosition());
			worldmanager.markForDelete(this);
		}
		return 1;
	}

	return 0;

}

//Move up or down
void BossSkull::moveY(int dy) {

	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos(getPosition().getX(), getPosition().getY() + dy);
	//If stays on screen, allow move
	if ((new_pos.getY() > 3) &&
		(new_pos.getY() < worldmanager.getBoundary().getVertical())) {
			worldmanager.moveObject(this, new_pos);
	}

}

void BossSkull::attack() {

	WorldManager &worldmanager = WorldManager::getInstance();
	if (random()%15 < 2) {
		Character *goodchar = new Character();
		goodchar->setXVelocity(-1);
		worldmanager.moveObject(goodchar,Position(60,this->getPosition().getY()));
	}
	else {
		EvilCharacter *attackchar = new EvilCharacter(0, true);
		attackchar->setXVelocity(-1);
		int trackingChance = random() % 10;
		if(trackingChance >= 8) // 20% chance to track
			attackchar->setTracksPlayer(true);
		worldmanager.moveObject(attackchar,Position(60,this->getPosition().getY()));
	}

}

void BossSkull::hit(EventCollision *p_c) {

	WorldManager &world_manager = WorldManager::getInstance();
	if ((p_c -> getObject1() -> getType()) == "BossSkull") {
		if ((p_c -> getObject2() -> getType()) == "Hero") {
			new LevelChange(1);
		}
		world_manager.markForDelete(p_c->getObject2());
	}
	else {
		if ((p_c -> getObject1() -> getType()) == "Hero") {
			new LevelChange(1);
		}
		world_manager.markForDelete(p_c->getObject1());
	}

}
