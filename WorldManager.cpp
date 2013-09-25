/*
 * WorldManager.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Josh
 */

//Game engine header files
#include "WorldManager.h"
#include "LogManager.h"

//Misc required headers

WorldManager::WorldManager() {

}

WorldManager &WorldManager::getInstance() {

	static WorldManager worldManager;
	return worldManager;

}

int WorldManager::startUp() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::startUp: Starting WorldManager\n");
	updates.clear();
	deletions.clear();
	Manager::startUp();
	return 0;

}

void WorldManager::shutDown() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::shutDown: Shutting down WorldManager\n");
	ObjectList update_copy = updates;   //Copy list so can delete during iteration.
	ObjectListIterator update_I(&update_copy);
	for (update_I.first(); !update_I.isDone(); update_I.next()) {
		delete update_I.currentObject();
	}

	Manager::shutDown();

}

int WorldManager::insertObject(Object *p_o) {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::insertObject: Inserting Object\n");
	return updates.insert(p_o);

}

int WorldManager::removeObject(Object *p_o) {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::removeObject: Removing object!\n");
	return updates.remove(p_o);

}

ObjectList WorldManager::getAllObjects() {

	return updates;

}

void WorldManager::update() {

	ObjectList deletion_copy = deletions;   //Copy list so can delete during iteration.
	ObjectListIterator deletion_I(&deletion_copy);
	for (deletion_I.first(); !deletion_I.isDone(); deletion_I.next()) {
		delete deletion_I.currentObject();
	}
	deletions.clear();

}

int WorldManager::markForDelete(Object *p_o) {

	//Check if object is in list already
	ObjectListIterator del_I = deletions.createIterator();
	  while (!del_I.isDone()) {
	    if (del_I.currentObject() == p_o) {
	      return 0; //Object already in list.
	    }
	    del_I.next();
	  }

	  return deletions.insert(p_o);

}

bool WorldManager::isValid(string event_type) {

	return false;

}

void WorldManager::draw() {

	ObjectListIterator iterator(&updates);

	for (int alt = 0; alt <= MAX_ALTITUDE; alt++) {
		while (!iterator.isDone()) {
			if (iterator.currentObject()->getAltitude() == alt) {
				iterator.currentObject()->draw();
			}
			iterator.next();
		}
		iterator.first();
	}

}
