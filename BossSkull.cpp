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

using namespace std;
using std::string;

BossSkull::BossSkull() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("BossSkull::BossSkull: Made the Boss!\n");

	ResourceManager &resourcemanager = ResourceManager::getInstance();
	setType("BossSkull");

	Sprite *p_temp_sprite = resourcemanager.getSprite("skull");
	if (!p_temp_sprite) {
			logmanager.writeLog("BossSkull::BossSkull(): Warning! Sprite '%s' not found", "skull");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(4);
	}

	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(((world_manager.getBoundary().getHorizontal()*5)/6), world_manager.getBoundary().getVertical()/2);
	setPosition(pos);
	setAltitude(2);

	health = 3;
	attack_countup = 0;
	move_countdown = 4;

}

BossSkull::~BossSkull() {

}

int BossSkull::eventHandler(Event *p_e) {

	if (p_e->getType() == COLLISION_EVENT) {
		health--;
		return 1;
	}

	if (p_e->getType() == STEP_EVENT) {
		attack_countup++;
		move_countdown--;
		if (move_countdown <= 0) {
			int move = random() % 5 - 2;
			moveY(move);
		}
		else if ((random() % (150 - (attack_countup/2)) + attack_countup) > 200) {
			attack();
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

	//TODO

}

