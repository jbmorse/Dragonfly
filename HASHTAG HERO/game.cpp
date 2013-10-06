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

//Misc required headers
#include "iostream"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"

int main() {

	//Game manager startup
	GameManager &gamemanager = GameManager::getInstance();
	int i = gamemanager.startUp(true, time(NULL));

	ResourceManager &resourcemanager = ResourceManager::getInstance();
	int j = resourcemanager.loadSprite("ship-spr.txt", "ship");
	if (j < 0) {
		LogManager &logmanager = LogManager::getInstance();
		logmanager.writeLog("Game.cpp: Error loading sprite!\n");
	}

	//World setup
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.setBoundary(Box(Position(0,0), 80, 50));
	new Hero();
	for (int i = 0; i < 10; i++) {
		new Character();
	}
	for (int i = 0; i < 40; i++) {
			new Star();
	}

	ViewObject *p_vo = new ViewObject; //Used for points
	p_vo->setViewString("Points");
	p_vo->setValue(0);
	p_vo->setLocation(TOP_RIGHT);
	p_vo->setColor(COLOR_YELLOW);

	//Run program
	gamemanager.run();
	//Program over, managers closed at end of loop in game manager

}


