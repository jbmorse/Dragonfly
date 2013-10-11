/*
 * LevelHandler.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */


// Class include
#include "LevelHandler.h"

// Engine includes
#include "GraphicsManager.h"
#include "Utility.h"
#include "SceneGraph.h"
#include "WorldManager.h"
#include "EventLevel.h"
#include "Character.h"
#include "Hero.h"
#include "CapturedString.h"
#include "BossSkull.h"
#include "LogManager.h"
#include "GameStart.h"
#include "TargetString.h"
#include "EvilCharacter.h"
#include "stdlib.h"

LevelHandler::LevelHandler() {

	setViewString("Level ");
	setType("LevelHandler");
	registerInterest(LEVEL_EVENT);
	setLocation(TOP_LEFT);
	level = 1;
	setPersistence(true);

}

LevelHandler &LevelHandler::getInstance() {

	static LevelHandler levelhandler;
	return levelhandler;

}

int LevelHandler::eventHandler(Event *p_e) {

	if(p_e->getType() == LEVEL_EVENT) {
		EventLevel *el = (EventLevel *) p_e;
		return 1;
	}

	return 0;

}

/*
 * Methods for all the levels of the game
 * Level 1 is menu, Level 2 is level 1, level 3 is level 2....
 */
void LevelHandler::restartGame() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("LevelHandler::restartGame: Restarting Game!\n");

	nextLevel(1);

}

void startLevel_2(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(2);

	//Hashtag Hero
	new Hero();

	//A few characters
	Character *char1 = new Character('W');
	Character *char2 = new Character('E');
	Character *char3 = new Character('L');
	Character *char4 = new Character('C');
	Character *char5 = new Character('O');
	Character *char6 = new Character('M');
	Character *char7 = new Character('E');

	char1->setPosition(Position(18,8));
	char2->setPosition(Position(25,8));
	char3->setPosition(Position(32,8));
	char4->setPosition(Position(39,8));
	char5->setPosition(Position(46,8));
	char6->setPosition(Position(53,8));
	char7->setPosition(Position(60,8));

	//Goal for collection
	new CapturedString("WELCOME");
	new TargetString("WELCOME");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_3(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(3);

	//Hashtag Hero
	new Hero();

	//A few characters
	new Character('R');
	new Character('E');
	new Character('D');
	new Character('I');
	new Character('S');
	new Character('B');
	new Character('A');
	new Character('D');

	for (int i = 0; i < 20; i++) {
		new Character();
	}

	for (int i = 0; i < 20; i++) {
		int j = random() % 25 + 1;
		new EvilCharacter(j, true);
	}

	//Goal for collection
	new CapturedString("REDISBAD");
	new TargetString("REDISBAD");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_4(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(4);

	//Hashtag Hero
	new Hero();

	//Characters to collect
	for (int i = 0; i < 150; i++) {
		new Character();
	}

	//Goal for collection
	new CapturedString("HI");
	new TargetString("HI");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_5(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(5);

	//Hashtag Hero
	new Hero();

	//BOSS FIGHT
	new BossSkull();

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

/*
 * Method sets the game to a new given level, and if not given, defaults to next
 */
void LevelHandler::nextLevel(int nextlevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	LogManager &logmanager = LogManager::getInstance();

	int prevLevel = level;
	if (nextlevel != 0) {
		level = nextlevel;
	}
	else level++;

	setValue(level - 1);

	switch (level) {
	case 1 :
		break;
	case 2 :
		startLevel_2(prevLevel);
		break;
	case 3 :
		startLevel_3(prevLevel);
		break;
	case 4 :
		startLevel_4(prevLevel);
		break;
	case 5 :
		startLevel_5(prevLevel);
		break;
	case 6 :
		setValue(0);
		level = 1;
		break;
	}

	logmanager.writeLog("Level %d\n", level);
	worldmanager.setLevel(level);

}

int LevelHandler::getLevel() {

	return level;

}
