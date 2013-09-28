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

//Misc required headers
#include "iostream"
#include "stdio.h"
#include "stdarg.h"
#include "unistd.h"

int main() {

	//Game manager startup
	GameManager &gamemanager = GameManager::getInstance();
	int i = gamemanager.startUp(true);

	//World setup
	WorldManager &worldmanager = WorldManager::getInstance();
	new Hero();
	for (int i = 0; i < 10; i++) {
		new Character();
	}
	for (int i = 0; i < 40; i++) {
			new Star();
	}
	//Run program
	gamemanager.run();
	//Program over, managers closed at end of loop in game manager

}


