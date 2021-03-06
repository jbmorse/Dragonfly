/*
 * GameStart.cpp

 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventKeyboard.h"
#include "GameManager.h"
#include "GameStart.h"
#include "GraphicsManager.h"
#include "Hero.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "CapturedString.h"
#include "TargetString.h"
#include "BossSkull.h"
#include "Character.h"
#include "Star.h"
#include "LevelHandler.h"

GameStart::GameStart() {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	//Setup GameStart sprite
	Sprite *p_temp_sprite = resource_manager.getSprite("gamestart");
	if (!p_temp_sprite) {
		log_manager.writeLog("GameStart::GameStart(): Warning! Sprite 'gamestart' not found", "gamestart");
	}
	else {
		setSprite(p_temp_sprite);
		setSpriteSlowdown(15);
	}

	setType("GameStart");

	showInstruct = false;

	//Put in center of screen
	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(world_manager.getBoundary().getCorner().getX() +
			world_manager.getBoundary().getHorizontal()/2,
			world_manager.getBoundary().getCorner().getY() +
			world_manager.getBoundary().getVertical()/2);
	setPosition(pos);

	//Register for "keyboard" event
	registerInterest(KEYBOARD_EVENT);

	log_manager.writeLog("GameStart::GameStart(): Made gamestart!\n");
	LevelHandler &levelhandler = LevelHandler::getInstance();

}

//Handle event; return 0 if ignored, else 1
int GameStart::eventHandler(Event *p_e) {

	LevelHandler &levelhandler = LevelHandler::getInstance();
	GameManager &game_manager = GameManager::getInstance();
	//Keyboard
	if (levelhandler.getLevel() != 1) {
		return 0;
	}
	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = (EventKeyboard *) p_e;
		switch (p_keyboard_event->getKey()) {
		case 'p':	//Play
			showInstructions(false); // change to start screen for when the player quits
			start();
			break;
		case 'q':	//Quit
			game_manager.setGameOver();
			break;
		case 'i':   // Show instructions
			showInstructions(!showInstruct);
			break;
		case '1':	//Checkpoint 1
			if (levelhandler.getCheckpoint() > 0) {
				levelhandler.nextLevel(6);
			}
			break;
		case '2':	//Checkpoint 2
			if (levelhandler.getCheckpoint() > 1) {
				levelhandler.nextLevel(7);
			}
			break;
		case '3':	//Checkpoint 3
			if (levelhandler.getCheckpoint() > 2) {
				levelhandler.nextLevel(9);
			}
			break;
		case '4':	//Checkpoint 4
			if (levelhandler.getCheckpoint() > 3) {
				levelhandler.nextLevel(10);
			}
			break;
		case '5':	//Checkpoint 5
			if (levelhandler.getCheckpoint() > 4) {
				levelhandler.nextLevel(11);
			}
			break;
		default:
			break;
		}
		return 1;
	}

	//If we get here, we have ignored this event
	return 0;

}

void GameStart::start() {

	//Start the next level
	LevelHandler &levelhandler = LevelHandler::getInstance();
	levelhandler.nextLevel(2);

}

//Override default draw so as not to display "value"
void GameStart::draw() {

	Object::draw();

}

void GameStart::showInstructions(bool show) {

	LogManager &log_manager = LogManager::getInstance();
	ResourceManager &resource_manager = ResourceManager::getInstance();

	showInstruct = show;

	if(!showInstruct) {  // Hiding instructions

		//Setup GameStart sprite
		Sprite *p_temp_sprite = resource_manager.getSprite("gamestart");
		if (!p_temp_sprite) {
			log_manager.writeLog("GameStart::showInstructions(): Warning! Sprite 'gamestart' not found", "gamestart");
		}
		else {
			log_manager.writeLog("GameStart::showInstructions(): Switching to start screen\n");
			setSprite(p_temp_sprite);
			setSpriteSlowdown(15);
		}
	} else {  // Showing instructions

		//Setup GameStart sprite
		Sprite *p_temp_sprite = resource_manager.getSprite("instructions");
		if (!p_temp_sprite) {
			log_manager.writeLog("GameStart::showInstructions(): Warning! Sprite 'gamestart' not found", "instructions");
		}
		else {
			log_manager.writeLog("GameStart::showInstructions(): Switching to instructions screen\n");
			log_manager.writeLog("Frame: %s\n", p_temp_sprite->getFrame(0).getString().c_str());
			setSprite(p_temp_sprite);
			setSpriteSlowdown(0);
		}
	}
}
