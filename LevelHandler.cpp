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
#include "PowerupHandler.h"
#include "TargetString.h"
#include "EvilCharacter.h"
#include "stdlib.h"
#include "SafeBox.h"
#include "BossFinal.h"
#include "Star.h"

LevelHandler::LevelHandler() {

	setViewString("Level ");
	setType("LevelHandler");
	registerInterest(LEVEL_EVENT);
	setLocation(TOP_LEFT);
	level = 1;
	setPersistence(true);
	checkpoint = 0;

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

	//Characters to collect
	for (int i = 0; i < 150; i++) {
		new Character();
	}
	new Character("H");
	new Character("I");

	//Goal for collection
	new CapturedString("HI");
	new TargetString("HI");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_4(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(4);

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

void startLevel_5(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(5);

	//Hashtag Hero
	Hero *hero = new Hero();
	hero->setPosition(Position(37,12));

	EvilCharacter *evil1 = new EvilCharacter(7, true);
	EvilCharacter *evil2 = new EvilCharacter(0, true);
	EvilCharacter *evil3 = new EvilCharacter(7, true);
	EvilCharacter *evil4 = new EvilCharacter(0, true);
	EvilCharacter *evil5 = new EvilCharacter(7, true);
	EvilCharacter *evil6 = new EvilCharacter(0, true);
	EvilCharacter *evil7 = new EvilCharacter(7, true);
	EvilCharacter *evil8 = new EvilCharacter(0, true);
	EvilCharacter *evil9 = new EvilCharacter(7, true);
	EvilCharacter *evil10 = new EvilCharacter(0, true);
	EvilCharacter *evil11 = new EvilCharacter(7, true);
	EvilCharacter *evil12 = new EvilCharacter(0, true);
	EvilCharacter *evil13 = new EvilCharacter(7, true);
	EvilCharacter *evil14 = new EvilCharacter(0, true);
	EvilCharacter *evil15 = new EvilCharacter(0, true);

	evil1->setPosition(Position(35,10));
	evil2->setPosition(Position(36,10));
	evil3->setPosition(Position(37,10));
	evil4->setPosition(Position(38,10));
	evil5->setPosition(Position(39,10));
	evil6->setPosition(Position(39,11));
	evil7->setPosition(Position(39,12));
	evil8->setPosition(Position(39,13));
	evil9->setPosition(Position(39,14));
	evil10->setPosition(Position(38,14));
	evil11->setPosition(Position(37,14));
	evil12->setPosition(Position(36,14));
	evil13->setPosition(Position(35,14));
	evil14->setPosition(Position(35,13));
	evil15->setPosition(Position(35,11));

	Character *char1 = new Character('B');
	Character *char2 = new Character('O');
	Character *char3 = new Character('X');
	Character *char4 = new Character('E');
	Character *char5 = new Character('D');
	Character *char6 = new Character('I');
	Character *char7 = new Character('N');

	//Goal for collection
	new CapturedString("BOXEDIN");
	new TargetString("BOXEDIN");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_6(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(6);

	//Hashtag Hero
	new Hero();

	// Powerups
	new PowerupHandler();

	//BOSS FIGHT
	new BossSkull();

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_7(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(7);

	//Hashtag Hero
	new Hero();

	EvilCharacter *evil1 = new EvilCharacter(7, false);
	EvilCharacter *evil2 = new EvilCharacter(5, false);
	EvilCharacter *evil3 = new EvilCharacter(15, false);
	EvilCharacter *evil4 = new EvilCharacter(19, false);
	EvilCharacter *evil5 = new EvilCharacter(24, false);
	EvilCharacter *evil6 = new EvilCharacter(1, false);
	EvilCharacter *evil7 = new EvilCharacter(4, false);
	EvilCharacter *evil8 = new EvilCharacter(22, false);
	EvilCharacter *evil9 = new EvilCharacter(11, false);
	EvilCharacter *evil10 = new EvilCharacter(0, false);

	evil1->setPosition(Position(15,15));
	evil1->setYVelocity(-.5);
	evil2->setPosition(Position(30,9));
	evil2->setYVelocity(.5);
	evil3->setPosition(Position(45,23));
	evil3->setYVelocity(-.4);
	evil4->setPosition(Position(60,15));
	evil4->setYVelocity(.5);
	evil5->setPosition(Position(15,15));
	evil5->setXVelocity(-.7);
	evil6->setPosition(Position(30,9));
	evil6->setXVelocity(.7);
	evil7->setPosition(Position(45,23));
	evil7->setXVelocity(-1);
	evil8->setPosition(Position(60,5));
	evil8->setXVelocity(.7);
	evil9->setPosition(Position(49,20));
	evil9->setXVelocity(-1.5);
	evil10->setPosition(Position(10,10));
	evil10->setYVelocity(.7);

	Character *char1 = new Character('B');
	Character *char2 = new Character('O');
	Character *char3 = new Character('U');
	Character *char4 = new Character('N');
	Character *char5 = new Character('C');
	Character *char6 = new Character('E');

	char1->setPosition(Position(13,4));
	char2->setPosition(Position(36,6));
	char3->setPosition(Position(59,7));
	char4->setPosition(Position(17,15));
	char5->setPosition(Position(33,17));
	char6->setPosition(Position(63,16));

	//Goal for collection
	new CapturedString("BOUNCE");
	new TargetString("BOUNCE");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_8(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(8);

	//Hashtag Hero
	new Hero();

	//Spawn protect hero
	new SafeBox(Position(7,7));
	new SafeBox(Position(7,10));
	new SafeBox(Position(7,13));
	new SafeBox(Position(7,16));
	new SafeBox(Position(4,7));
	new SafeBox(Position(4,10));
	new SafeBox(Position(4,13));
	new SafeBox(Position(4,16));
	new SafeBox(Position(10,7));
	new SafeBox(Position(10,10));
	new SafeBox(Position(10,13));
	new SafeBox(Position(10,16));

	for (int i = 0; i < 10; i++) {
		new EvilCharacter();
	}

	for (int i = 0; i < 20; i++) {
		new Character();
	}

	new Character('D');
	new Character('A');
	new Character('N');
	new Character('G');
	new Character('E');
	new Character('R');

	//Goal for collection
	new CapturedString("DANGER");
	new TargetString("DANGER");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_9(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(9);

	//Hashtag Hero
	new Hero();

	//Spawn protect hero
	new SafeBox(Position(7,7));
	new SafeBox(Position(7,10));
	new SafeBox(Position(7,13));
	new SafeBox(Position(7,16));
	new SafeBox(Position(4,7));
	new SafeBox(Position(4,10));
	new SafeBox(Position(4,13));
	new SafeBox(Position(4,16));
	new SafeBox(Position(10,7));
	new SafeBox(Position(10,10));
	new SafeBox(Position(10,13));
	new SafeBox(Position(10,16));

	for (int i = 0; i < 8; i++) {
		new EvilCharacter();
	}

	for (int i = 0; i < 100; i++) {
		new Character();
	}

	new Character('C');
	new Character('O');
	new Character('N');
	new Character('F');
	new Character('U');
	new Character('S');
	new Character('I');
	new Character('O');
	new Character('N');

	//Goal for collection
	new CapturedString("CONFUSION");
	new TargetString("CONFUSION");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_10(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(10);

	//Hashtag Hero
	new Hero();

	//Spawn protect hero
	new SafeBox(Position(7,7));
	new SafeBox(Position(7,10));
	new SafeBox(Position(7,13));
	new SafeBox(Position(7,16));
	new SafeBox(Position(4,7));
	new SafeBox(Position(4,10));
	new SafeBox(Position(4,13));
	new SafeBox(Position(4,16));
	new SafeBox(Position(10,7));
	new SafeBox(Position(10,10));
	new SafeBox(Position(10,13));
	new SafeBox(Position(10,16));

	for (int i = 0; i < 20; i++) {
		int j = random() % 25 + 1;
		new EvilCharacter(j, true);
	}

	for (int i = 0; i < 20; i++) {
		new EvilCharacter();
	}

	//Goal for collection
	new CapturedString("GOODLUCK");
	new TargetString("GOODLUCK");

	new Character('G');
	new Character('O');
	new Character('O');
	new Character('D');
	new Character('L');
	new Character('U');
	new Character('C');
	new Character('K');

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_11(int prevLevel) {

	//FINAL LEVEL

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();

	scenegraph.setLevel(11);

	//Hashtag Hero
	new Hero();

	//Hyper stars!
	for (int i = 0; i < 50; i++) {
		new Star();
	}

	//FINAL BOSS
	new BossFinal();

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
		if (checkpoint < 1) {
			checkpoint = 1;
		}
		startLevel_6(prevLevel);
		break;
	case 7 :
		if (checkpoint < 2) {
			checkpoint = 2;
		}
		startLevel_7(prevLevel);
		break;
	case 8 :
		startLevel_8(prevLevel);
		break;
	case 9 :
		if (checkpoint < 3) {
			checkpoint = 3;
		}
		startLevel_9(prevLevel);
		break;
	case 10 :
		startLevel_10(prevLevel);
		break;
	case 11 :
		if (checkpoint < 4) {
			checkpoint = 4;
		}
		startLevel_11(prevLevel);
		break;
	case 12 :
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

int LevelHandler::getCheckpoint() {

	return checkpoint;

}

void LevelHandler::setCheckpoint(int newcheckpoint) {

	checkpoint = newcheckpoint;

}
