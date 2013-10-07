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
#include "Points.h"
#include "ResourceManager.h"
#include "Saucer.h"
#include "WorldManager.h"

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

	//Put in center of screen
	WorldManager &world_manager = WorldManager::getInstance();
	Position pos(world_manager.getBoundary().getCorner().getX() +
			world_manager.getBoundary().getHorizontal()/2,
			world_manager.getBoundary().getCorner().getY() +
			world_manager.getBoundary().getVertical()/2);
	setPosition(pos);

	//Register for "keyboard" event
	registerInterest(KEYBOARD_EVENT);

}

//Handle event; return 0 if ignored, else 1
int GameStart::eventHandler(Event *p_e) {

	GameManager &game_manager = GameManager::getInstance();
	//Keyboard
	if (p_e->getType() == KEYBOARD_EVENT) {
		EventKeyboard *p_keyboard_event = (EventKeyboard *) p_e;
		switch (p_keyboard_event->getKey()) {
		case 'p':	//Play
			start();
			break;
		case 'q':	//Quit
			game_manager.setGameOver();
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

	WorldManager &world_manager = WorldManager::getInstance();
	SceneGraph &scene_graph = world_manager.getSceneGraph();

	//Will populate play world with objects
	scene_graph.setLevel(PLAY_LEVEL);

	//Spawn the enemies
	for (int i=0; i<16; i++)
		new Saucer;

	//Spawn player
	new Hero;

	//Setup Points display
	new Points;

	//Setup Nuke Count
	ViewObject *p_vo = new ViewObject;
	p_vo->setLocation(TOP_LEFT);
	p_vo->setViewString("Nukes");
	p_vo->setValue(1);
	p_vo->setColor(COLOR_YELLOW);

	//Revert back to menu
	scene_graph.setLevel(MENU_LEVEL);

	//Tell world manager to goto game level
	world_manager.setLevel(PLAY_LEVEL);

}

//Override default draw so as not to display "value"
void GameStart::draw() {

	Object::draw();

}

