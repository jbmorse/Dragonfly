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
#include "Pointstemp.h"
#include "CapturedString.h"

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

}

void populateWorld() {

	//World setup
	WorldManager &worldmanager = WorldManager::getInstance();
	new Hero();
	for (int i = 0; i < 10; i++) {
		new Character();
	}
	for (int i = 0; i < 40; i++) {
		//TODO
		//Maybe make stars move different directions?
		//No longer flying to right all the time
		new Star();
	}
	new BossSkull();
	//Setup Points display
	new Pointstemp;

	CapturedString *cs = new CapturedString();
	cs->setViewString("testing");

	//TODO
	//Add points

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


