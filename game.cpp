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
	resource_manager.loadSprite("sprites/explosion-spr.txt", "explosion");
	resource_manager.loadSprite("sprites/skull1-spr.txt", "skull1");
	resource_manager.loadSprite("sprites/skull2-spr.txt", "skull2");
	resource_manager.loadSprite("sprites/skull3-spr.txt", "skull3");
	resource_manager.loadSprite("sprites/gameover-spr.txt", "gameover");
	resource_manager.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	resource_manager.loadSprite("sprites/goodjob-spr.txt", "goodjob");
	resource_manager.loadSprite("sprites/powerup-shield-spr.txt", "powerup-shield");
	resource_manager.loadSprite("sprites/hashtag-w-shield-spr.txt", "hashtag-shield");
	resource_manager.loadSprite("sprites/youwin-spr.txt", "youwin");
	resource_manager.loadSprite("sprites/safebox-spr.txt", "safebox");
	resource_manager.loadSprite("sprites/finalboss1-spr.txt", "finalboss1");
	resource_manager.loadSprite("sprites/finalboss2-spr.txt", "finalboss2");
	resource_manager.loadSprite("sprites/finalboss3-spr.txt", "finalboss3");
	resource_manager.loadSprite("sprites/explosion-spr.txt", "finalexplosion");

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


