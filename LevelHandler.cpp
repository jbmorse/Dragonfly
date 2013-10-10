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

	nextLevel(1);
	//TODO
	//Reset points and hide level

}

void startLevel_2(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(2);

	//Hashtag Hero
	new Hero();

	//Characters to collect
	for (int i = 0; i < 150; i++) {
		new Character();
	}

	//Goal for collection
	new CapturedString("Hi");

	//Revert back to previous level
	scenegraph.setLevel(prevLevel);

}

void startLevel_3(int prevLevel) {

	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scenegraph = worldmanager.getSceneGraph();
	scenegraph.setLevel(3);

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

	//Remove Objects from current level
	WorldManager &worldmanager = WorldManager::getInstance();

	ObjectList object_list = worldmanager.getAllObjects();
	ObjectListIterator i(&object_list);
	for (i.first(); !i.isDone(); i.next()) {
		Object *p_o = i.currentObject();
		if (!p_o->isPersistent()) {
			worldmanager.markForDelete(p_o);
		}
	}

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
		restartGame();
		break;
	}

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Level %d", level);
	worldmanager.setLevel(level);

}
