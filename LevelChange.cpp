/*
 * GameOver.cpp

 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "LevelHandler.h"
#include "LevelChange.h"

LevelChange::LevelChange(int level) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	Sprite *p_temp_sprite;
	if (level == 12) {
		//Setup GoodJob sprite
		p_temp_sprite = resource_manager.getSprite("youwin");
	}
	else if (level != 1) {
		//Setup GoodJob sprite
		p_temp_sprite = resource_manager.getSprite("goodjob");
	}
	else {
		//Setup GameOver sprite
		p_temp_sprite = resource_manager.getSprite("gameover");
	}
	if (!p_temp_sprite) {
		log_manager.writeLog("LevelChange::LevelChange(): Warning! Sprite 'levelchange' not found");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(10);
		time_to_live = p_temp_sprite->getFrameCount() * 10;
	}

	setType("LevelChange");

	setAltitude(4);

	//Put in center of screen
	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(world_manager.getBoundary().getCorner().getX() +
			world_manager.getBoundary().getHorizontal()/2,
			world_manager.getBoundary().getCorner().getY() +
			world_manager.getBoundary().getVertical()/2);
	setPosition(pos);

	//Register for step event
	registerInterest(STEP_EVENT);

	nextlevel = level;

	log_manager.writeLog("LevelChange::LevelChange(): New levelchange!\n");

}

//When object exits, indicate game over
LevelChange::~LevelChange() {

	LevelHandler &levelhandler = LevelHandler::getInstance();

	if (nextlevel == 1) {
		//Go to start level
		levelhandler.restartGame();
	}
	else {
		//Go to next level
		levelhandler.nextLevel(nextlevel);
	}

}

int LevelChange::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

//Count down to end of message
void LevelChange::step() {

	time_to_live--;
	if (time_to_live <= 0) {
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
	}

	if (time_to_live == 10) {
		//Remove Objects from current level
		WorldManager &worldmanager = WorldManager::getInstance();

		ObjectList object_list = worldmanager.getAllObjects();
		ObjectListIterator i(&object_list);
		for (i.first(); !i.isDone(); i.next()) {
			Object *p_o = i.currentObject();
			if (!p_o->isPersistent() && p_o != this) {
				worldmanager.markForDelete(p_o);
			}
		}
	}

}

//Override default draw so as not to display "value"
void LevelChange::draw() {

	Object::draw();

}
