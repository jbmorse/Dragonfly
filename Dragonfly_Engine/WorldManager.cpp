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
#include "ViewObject.h"

//Misc required headers

WorldManager::WorldManager() {

	p_view_following = NULL;
	next_level = 0;

}

WorldManager &WorldManager::getInstance() {

	static WorldManager worldManager;
	return worldManager;

}

int WorldManager::startUp() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::startUp: Starting WorldManager\n");
	deletions.clear();
	Manager::startUp();
	return 0;

}

void WorldManager::shutDown() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::shutDown: Shutting down WorldManager\n");
	ObjectList objects_copy = scene_graph.allObjects();   //Copy list so can delete during iteration.
	ObjectListIterator update_I(&objects_copy);
	for (update_I.first(); !update_I.isDone(); update_I.next()) {
		delete update_I.currentObject();
	}

	Manager::shutDown();

}

int WorldManager::insertObject(Object *p_o) {

	return scene_graph.insertObject(p_o);

}

int WorldManager::removeObject(Object *p_o) {

	return scene_graph.removeObject(p_o);

}

ObjectList WorldManager::getAllObjects() {

	return scene_graph.allObjects();

}

void WorldManager::update() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("WorldManager::Update: Updating\n");

	//Move objects based on velocity
	ObjectList all_objects = scene_graph.allObjects();
	ObjectListIterator v_i = ObjectListIterator(&all_objects);
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
	int i = 0;
	for (deletion_I.first(); !deletion_I.isDone(); deletion_I.next()) {
		i++;
		logmanager.writeLog("deletion %d\n", i);
		delete deletion_I.currentObject();
	}
	deletions.clear();

	if (next_level) {
		scene_graph.setLevel(next_level);
		next_level = 0;
	}

	logmanager.writeLog("WorldManager::Update: Done updating\n");

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

	for (int alt = 0; alt <= MAX_ALTITUDE; alt++) {
		ObjectList alt_objs = scene_graph.visibleObjects(alt);
		ObjectListIterator iterator = ObjectListIterator(&alt_objs);

		while (!iterator.isDone()) {
			Object *p_temp_o = iterator.currentObject();
			if (p_temp_o->getAltitude() == alt) {

				//Convert to world coordinates
				Box temp_box = getWorldBox(p_temp_o);

				//Only draw if Object would be visible on screen
				if (boxIntersectsBox(temp_box, view) ||
					dynamic_cast <ViewObject *> (p_temp_o)) {
					p_temp_o->draw();
				}
			}
			iterator.next();
		}
	}

}

ObjectList WorldManager::isCollision(Object *p_o, Position where) {

	ObjectList collisions;
	ObjectList solid_objects = scene_graph.solidObjects();
	ObjectListIterator iterator = ObjectListIterator(&solid_objects);

	while (!iterator.isDone()) {
		Object *p_temp_o = iterator.currentObject();
		if (p_temp_o != p_o) {
			Box new_box = p_o->getBox();
			new_box.setCorner(where);
			if (boxIntersectsBox(getWorldBox(p_temp_o), new_box) &&
					(p_temp_o->isSolid()))
			{
				collisions.insert(p_temp_o);
			}
		}
		iterator.next();
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

	if (p_view_following == p_o) {
		setViewPosition(p_o->getPosition());
	}

	return 0; //Successful move

}

Box WorldManager::getBoundary() {

	return boundary;

}

void WorldManager::setBoundary(Box new_boundary) {

	boundary = new_boundary;

}

Box WorldManager::getView() {

	return view;

}

void WorldManager::setView(Box new_view) {

	view = new_view;

}

void WorldManager::setViewPosition(Position view_pos) {

	//Make sure horizontal inside boundary
	int x = view_pos.getX() - view.getHorizontal() /2;
	if (x + view.getHorizontal() > boundary.getHorizontal()) {
		x = boundary.getHorizontal() - view.getHorizontal();
	}

	if (x < 0) {
		x = 0;
	}

	//Make sure vertical inside boundary
	int y = view_pos.getY() - view.getVertical() /2;
	if (y + view.getVertical() > boundary.getVertical()) {
		y = boundary.getVertical() - view.getVertical();
	}

	if (y < 0) {
		y = 0;
	}

	Position new_corner(x, y);
	view.setCorner(new_corner);

}

int WorldManager::setViewFollowing(Object *p_new_view_following) {

	//Set to NULL to turn `off' following
	if (p_new_view_following == NULL) {
		p_view_following = NULL;
		return 0;
	}

	ObjectList all_objects = scene_graph.allObjects();
	ObjectListIterator iterator = ObjectListIterator(&all_objects);
	while (!iterator.isDone()) {
		Object *p_temp_o = iterator.currentObject();
		if (p_temp_o == p_new_view_following) {
			p_view_following = p_new_view_following;
			setViewPosition(p_view_following -> getPosition());
			return 0;
		}
		iterator.next();
	}

	return -1; //Did not find object

}

SceneGraph &WorldManager::getSceneGraph() {

	return scene_graph;

}

int WorldManager::getLevel() {

	return scene_graph.getLevel();

}
int WorldManager::setLevel(int new_level) {

	if (valueInRange(new_level, 0, MAX_LEVEL)) {
		next_level = new_level;
		return 0;
	}

	return -1;

}
