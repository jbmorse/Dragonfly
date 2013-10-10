/*
 * game.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Clock.h"
#include "LogManager.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "Hero.h"
#include "Character.h"
#include "Star.h"
#include "ResourceManager.h"
#include "GraphicsManager.h"
#include "ViewObject.h"
#include "BossSkull.h"
#include "CapturedString.h"
#include "GameStart.h"

//Misc required headers
#include "iostream"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"

void loadResources() {

	//Load sprites
	ResourceManager &resource_manager = ResourceManager::getInstance();
	resource_manager.loadSprite("sprites/hashtag-spr.txt", "hashtag");
	resource_manager.loadSprite("sprites/boss1-spr.txt", "skull");
	resource_manager.loadSprite("sprites/gameover-spr.txt", "gameover");
	resource_manager.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	resource_manager.loadSprite("sprites/goodjob-spr.txt", "goodjob");

}

void populateWorld() {

	//Start the game
	new GameStart();

}

int main() {

	//Game manager startup
	GameManager &gamemanager = GameManager::getInstance();
	int i = gamemanager.startUp(true, time(NULL));

    //Load the sprites
    loadResources();

    //Populate world with objects
    populateWorld();

	//Run game
	gamemanager.run();

}


