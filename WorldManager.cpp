/*
 * WorldManager.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Josh
 */

//Game engine header files
#include "WorldManager.h"
#include "LogManager.h"
#include "Utility.h"
#include "EventCollision.h"
#include "GraphicsManager.h"
#include "EventOut.h"

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

	return updates.insert(p_o);

}

int WorldManager::removeObject(Object *p_o) {

	return updates.remove(p_o);

}

ObjectList WorldManager::getAllObjects() {

	return updates;

}

void WorldManager::update() {

	//Move objects based on velocity
	ObjectListIterator v_i = ObjectListIterator(&updates);
	while (!v_i.isDone()) {
		int x = v_i.currentObject()->getXVelocityStep();
		int y = v_i.currentObject()->getYVelocityStep();
		if (x != 0 || y != 0) {
			Position old_position = v_i.currentObject()->getPosition();
			Position new_position = Position(old_position.getX() + x, old_position.getY() + y);
			moveObject(v_i.currentObject(), new_position);
		}
		v_i.next();
	}

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

ObjectList WorldManager::isCollision(Object *p_o, Position where) {

	ObjectList collisions;
	ObjectListIterator i = ObjectListIterator(&updates);
	while (!i.isDone()) {
		Object *p_temp_o = i.currentObject();
		if (p_temp_o != p_o) {
			if (positionsIntersect(p_temp_o->getPosition(), where) &&
					(p_temp_o->isSolid()))
			{
				collisions.insert(p_temp_o);
			}
		}
		i.next();
	}

	return collisions;

}

int WorldManager::moveObject(Object *p_o, Position where) {

	bool doMove = true;

	if (p_o->isSolid()) {
		ObjectList collisions = isCollision(p_o, where);
		if (!collisions.isEmpty()) {
			ObjectListIterator i(&collisions);
			while (!i.isDone()) {
				Object *p_temp_o = i.currentObject();

				EventCollision c(p_o, p_temp_o, where);
				p_o->eventHandler(&c);
				p_temp_o->eventHandler(&c);

				if (p_temp_o->getSolidness() == HARD &&
					p_o->getSolidness() == HARD) {
					doMove = false; //Collision with hard solid
				}
				i.next();
			}//End iterate

			if (!doMove) {
				return -1; //Can not move
			}

		}//No collisions
	}//Not solid

	Position prev_pos = p_o->getPosition();
	p_o->setPosition(where);

	//Check for out of bounds
	bool out;
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	int xBorder = graphicsmanager.getHorizontal();
	int yBorder = graphicsmanager.getVertical();
	if (prev_pos.getX() >= 0 && where.getX() < 0) {
		out = true; //Went out the left side
	}
	else if (prev_pos.getX() <= xBorder && where.getX() > xBorder) {
		out = true; //Went out the right side
	}
	else if (prev_pos.getY() >= 0 && where.getY() < 0) {
		out = true; //Went out the top side
	}
	else if (prev_pos.getY() <= yBorder && where.getY() > yBorder) {
		out = true; //Went out the bottom side
	}
	if (out == true) {
		EventOut ov = EventOut();
		p_o->eventHandler(&ov);
	}

	return 0; //Successful move

}
