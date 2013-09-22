/*
 * GameManager.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "GameManager.h"
#include "LogManager.h"
#include "Clock.h"
#include "Event.h"
#include "EventStep.h"
#include "ObjectListIterator.h"
#include "WorldManager.h"

//Misc required headers
#include "time.h"
#include "unistd.h"

#define DEFAULT_FRAME_TIME 33 //Measured in milliseconds

GameManager::GameManager() {

	game_over = false;
	frame_time = 0;

}

GameManager::~GameManager() {

}

GameManager &GameManager::getInstance() {

	static GameManager gameManager;
	return gameManager;

}

int GameManager::startUp(bool flush) {

	int failedServices = 0; //Keeps track of how many things failed

	//Start LogManager
	LogManager &logmanager = LogManager::getInstance();
	failedServices += logmanager.startUp(flush);
	logmanager.writeLog("GameManager::startUp: Log Manager started\n");
	WorldManager &worldmanager = WorldManager::getInstance();
	failedServices += worldmanager.startUp();
	logmanager.writeLog("GameManager::startUp: World Manager started\n");

	return failedServices; //If 0, complete success

}

int GameManager::startUp() {

	return startUp(false);

}

void GameManager::shutDown() {

	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.shutDown();
	LogManager &logmanager = LogManager::getInstance();
	logmanager.shutDown();

}

void GameManager::run(int fr_time) {

	frame_time = fr_time;
	long int loop_time;
	Clock clock;

	//MAIN GAME LOOP
	int i = 0;
	int sleep_time;
	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("GameManager::run: Game loop begins (30 timing statements will follow)\n");
	while (!game_over) {
		clock.delta();
		//get input//
		//update world//
		//Send step event to all objects
		WorldManager &worldmanager = WorldManager::getInstance();
		ObjectList all_objects = worldmanager.getAllObjects();
		EventStep *s = new EventStep();
		ObjectListIterator iter = all_objects.createIterator();
		while (!iter.isDone()) {
			iter.currentObject()->eventHandler((Event *)s);
			iter.next();
		}
		loop_time = clock.split();
		sleep_time = frame_time - loop_time;
		i++;
		if (i == 30) setGameOver();
		if (i == 20) {
			iter.first();
			worldmanager.markForDelete(iter.currentObject());
		}
		worldmanager.update();
		//draw new screen//
		//swap buffer//
		usleep(sleep_time*1000);
	}
	logmanager.writeLog("GameManager::run: Game loop ends\n");
	shutDown();

}

void GameManager::setGameOver() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("GameManager::setGameOver: Game Over!\n");
	game_over = true;

}

void GameManager::setGameOver(bool new_game_over) {

	game_over = new_game_over;

}

int GameManager::getFrameTime() {

	return frame_time;

}

bool GameManager::isValid(string event_type) {

	return false;

}

