/*
 * BossFinal.cpp
 *
 *  Created on: Oct 14, 2013
 *      Author: Josh
 */

#include "BossFinal.h"
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

BossFinal::BossFinal() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("BossFinal::BossFinal: Made the Boss!\n");

	ResourceManager &resourcemanager = ResourceManager::getInstance();
	setType("BossFinal");

	Sprite *p_temp_sprite = resourcemanager.getSprite("finalboss1");
	if (!p_temp_sprite) {
			logmanager.writeLog("BossFinal::BossFinal(): Warning! Sprite '%s' not found", "finalboss1");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(4);
	}

	//Step to disappear
	registerInterest(STEP_EVENT);
	registerInterest(CAPTURED_LETTER_EVENT);

	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(((world_manager.getBoundary().getHorizontal()*5)/6), world_manager.getBoundary().getVertical()/2 + 2);
	setPosition(pos);
	setAltitude(2);

	health = 3;
	attack_countup = 0;

}

BossFinal::~BossFinal() {

}

int BossFinal::eventHandler(Event *p_e) {

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
		if ((random() % 200 + attack_countup) > 200) {
			attack();
			attack_countup = 0;
		}
		return 1;
	}
	if (p_e->getType() == CAPTURED_LETTER_EVENT) {
		health--;
		//If health 2, set next sprite
		if (health == 2) {
			Sprite *p_temp_sprite = resourcemanager.getSprite("finalboss2");
			if (!p_temp_sprite) {
				logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "finalboss2");
			}
			else {
				setSprite(p_temp_sprite);
				setSpriteSlowdown(4);
			}
		}
		//If health 1, set to almost dead sprite
		if (health == 1) {
			Sprite *p_temp_sprite = resourcemanager.getSprite("finalboss3");
			if (!p_temp_sprite) {
				logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "finalboss3");
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

			//Level over, make hero spectral
			ObjectList objects_copy = worldmanager.getAllObjects();
			ObjectListIterator i(&objects_copy);
			for (i.first(); !i.isDone(); i.next()) {
				if (i.currentObject()->getType().compare("Hero") == 0) {
					i.currentObject()->setSolidness(SPECTRAL);
				}
			}

		}
		return 1;
	}

	return 0;

}

void BossFinal::attack() {

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

void BossFinal::hit(EventCollision *p_c) {

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
