/*
 * GameOver.cpp

 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "GameManager.h"
#include "GameOver.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

GameOver::GameOver() {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup GameOver sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("gameover");
	if (!p_temp_sprite) {
		log_manager.writeLog("GameOver::GameOver(): Warning! Sprite 'gameover' not found", "gameover");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(15);
		time_to_live = p_temp_sprite->getFrameCount() * 15;
	}

	setType("GameOver");

	//Put in center of screen
	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(world_manager.getBoundary().getCorner().getX() +
			world_manager.getBoundary().getHorizontal()/2,
			world_manager.getBoundary().getCorner().getY() +
			world_manager.getBoundary().getVertical()/2);
	setPosition(pos);

	//Register for step event
	registerInterest(STEP_EVENT);

}

//When object exits, indicate game over
GameOver::~GameOver() {

	//Remove Saucers and ViewObjects
	WorldManager &world_manager = WorldManager::getInstance();
	ObjectList object_list = world_manager.getAllObjects();
	ObjectListIterator i(&object_list);
	for (i.first(); !i.isDone(); i.next()) {
		Object *p_o = i.currentObject();
		if (p_o -> getType() == "Saucer" || p_o -> getType() == "ViewObject") {
			world_manager.markForDelete(p_o);
		}
	}

}

int GameOver::eventHandler(Event *p_e) {

	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

	return 0;

}

//Count down to end of message
void GameOver::step() {

	time_to_live--;
	if (time_to_live <= 0) {
		WorldManager &world_manager = WorldManager::getInstance();
		world_manager.markForDelete(this);
		GameManager &gamemanager = GameManager::getInstance();
		gamemanager.setGameOver();
	}

}

//Override default draw so as not to display "value"
void GameOver::draw() {

	Object::draw();

}
