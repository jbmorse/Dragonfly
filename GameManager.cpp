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
#include "GraphicsManager.h"
#include "InputManager.h"

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

	//Start Graphics Manager
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	failedServices += graphicsmanager.startUp();
	if (failedServices == 0) logmanager.writeLog("GameManager::startUp: Graphics Manager started\n");

	//Start Input Manager
	InputManager &inputmanager = InputManager::getInstance();
	failedServices += inputmanager.startUp();
	if (failedServices == 0) logmanager.writeLog("GameManager::startUp: Input Manager started\n");

	//Start World Manager
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
	InputManager &inputmanager = InputManager::getInstance();
	inputmanager.shutDown();
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.shutDown();
	LogManager &logmanager = LogManager::getInstance();
	logmanager.shutDown();

}

void GameManager::run(int fr_time) {

	frame_time = fr_time;
	long int loop_time;
	Clock clock;
	WorldManager &worldmanager = WorldManager::getInstance();
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	InputManager &inputmanager = InputManager::getInstance();
	LogManager &logmanager = LogManager::getInstance();

	//MAIN GAME LOOP
	int i = 0;
	int sleep_time;
	logmanager.writeLog("GameManager::run: Game loop begins\n");
	while (!game_over) {
		clock.delta();
		inputmanager.getInput();
		EventStep s = EventStep();
		onEvent(&s);
		worldmanager.update();
		worldmanager.draw();
		graphicsmanager.swapBuffers();
		loop_time = clock.split();
		usleep((frame_time-loop_time)*1000);
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
