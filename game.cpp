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

//Misc required headers
#include "iostream"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"

int main() {

	//Game manager startup
	GameManager &gamemanager = GameManager::getInstance();
	gamemanager.startUp(true);

	//World setup
	WorldManager &worldmanager = WorldManager::getInstance();
	new Hero();

	//Run program
	gamemanager.run();
	//Program over, managers closed at end of loop in game manager

}


