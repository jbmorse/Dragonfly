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
#include "FinalBossExplosion.h"
#include "Star.h"

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
	Position pos(((world_manager.getBoundary().getHorizontal()*9)/10), world_manager.getBoundary().getVertical()/2 + 2);
	setPosition(pos);
	setAltitude(2);

	health = 3;
	attack_countup = 0;
	chartimer = 0;
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
		chartimer++;
		attack_countup++;

		if (health == 3) {
			if ((random() % 100 + attack_countup) > 100) {
				attack1();
				attack_countup = 0;
			}
		}

		if (health == 2) {
			if ((random() % 100 + attack_countup) > 92) {
				attack2();
				attack_countup = 0;
			}
		}

		if (health == 1) {
			laser();
			if ((random() % 100 + attack_countup) > 90) {
				attack3();
				attack_countup = 0;
			}
		}
		if (chartimer >= 299) {
			if (chartimer%100 == 0) {
				Character *goodchar = new Character();
				goodchar->setXVelocity(-1);
				worldmanager.moveObject(goodchar,Position(this->getPosition().getX()-5, this->getPosition().getY()));
			}
		}

		return 1;
	}


	if (p_e->getType() == CAPTURED_LETTER_EVENT) {
		health--;
		chartimer = 0;
		attack_countup = 0;
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
			new FinalBossExplosion(this->getPosition());
			worldmanager.markForDelete(this);

			//Level over, make hero spectral and stars no longer hyper
			ObjectList objects_copy = worldmanager.getAllObjects();
			ObjectListIterator i(&objects_copy);
			for (i.first(); !i.isDone(); i.next()) {
				if (i.currentObject()->getType().compare("Hero") == 0) {
					i.currentObject()->setSolidness(SPECTRAL);
				}
				if (i.currentObject()->getType().compare("Star") == 0) {
					Star *s = (Star*) i.currentObject();
					s->removeHyper();
				}
			}
		}
		return 1;//CapturedLetterEvent
	}

	return 0;

}

void BossFinal::laser() {

	WorldManager &worldmanager = WorldManager::getInstance();

	if (random()%2) {
	EvilCharacter *attackchar1 = new EvilCharacter(0, true);
	attackchar1->setXVelocity(-1);
	worldmanager.moveObject(attackchar1,Position(this->getPosition().getX()-5, this->getPosition().getY() - 3));
	}

	if (random()%2) {
	EvilCharacter *attackchar3 = new EvilCharacter(0, true);
	attackchar3->setXVelocity(-1);
	worldmanager.moveObject(attackchar3,Position(this->getPosition().getX()-5, this->getPosition().getY() + 3));
	}

}

void BossFinal::attack1() {

	WorldManager &worldmanager = WorldManager::getInstance();

	EvilCharacter *attackchar = new EvilCharacter(0, true);
	attackchar->setXVelocity(-1);
	int trackingChance = random() % 10;
	if(trackingChance >= 8) // 20% chance to track
		attackchar->setTracksPlayer(true);
	worldmanager.moveObject(attackchar,Position(this->getPosition().getX()-5,random() % (worldmanager.getBoundary().getVertical() - 5) + 4));

}

void BossFinal::attack2() {

	WorldManager &worldmanager = WorldManager::getInstance();

	EvilCharacter *attackchar = new EvilCharacter(0, true);
	attackchar->setXVelocity(-1);
	int trackingChance = random() % 10;
	if(trackingChance >= 7) // 30% chance to track
		attackchar->setTracksPlayer(true);
	worldmanager.moveObject(attackchar,Position(this->getPosition().getX()-5,random() % (worldmanager.getBoundary().getVertical() - 5) + 4));

}

void BossFinal::attack3() {

	WorldManager &worldmanager = WorldManager::getInstance();

	EvilCharacter *attackchar = new EvilCharacter(0, true);
	attackchar->setXVelocity(-1);
	worldmanager.moveObject(attackchar,Position(this->getPosition().getX()-5, random() % 5  + (this->getPosition().getY() - 2)));

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
