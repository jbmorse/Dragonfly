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

//Misc required headers
#include "iostream"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"

int main() {

	//Clock setup
	Clock * clock = new Clock();

	//Game manager startup
	GameManager &gamemanager = GameManager::getInstance();
	gamemanager.startUp(true);

	//Timer Test
	clock->delta();
	usleep(20000);
	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Sleep test: Should be roughly 20: %d\n", clock->delta());

	//World setup
	WorldManager &worldmanager = WorldManager::getInstance();
	new Object();
	Object *o = new Object();
	o->setPosition(Position(5,7));

	//Run program
	gamemanager.run();
	//Program over, managers closed at end of loop in game manager

}


