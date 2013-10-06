/*
 * SceneGraph.cpp
 *
 *  Created on: Oct 4, 2013
 *      Author: Josh
 */

//Game engine header files
#include "SceneGraph.h"
#include "Utility.h"

//Misc required headers

SceneGraph::SceneGraph() {

	level = 1;

}

SceneGraph::~SceneGraph() {

}

int SceneGraph::insertObject(Object *p_o) {

	objects[level].insert(p_o);

	if (p_o->isSolid()) {
		solid_objects[level].insert(p_o);
	}

	if (!valueInRange(p_o->getAltitude(), 0, MAX_ALTITUDE)) {
		return -1;
	}

	visible_objects[level][p_o->getAltitude()].insert(p_o);

	return 0;

}

int SceneGraph::removeObject(Object *p_o) {

	objects[level].remove(p_o);

	solid_objects[level].remove(p_o);

	visible_objects[level][p_o->getAltitude()].remove(p_o);

	return 0;

}

ObjectList SceneGraph::allObjects() {

	return objects[level];

}

ObjectList SceneGraph::solidObjects() {

	return solid_objects[level];

}

ObjectList SceneGraph::visibleObjects(int altitude) {

	if (valueInRange(altitude, 0, MAX_ALTITUDE)) {
		return visible_objects[level][altitude];
	}

	else return visible_objects[level][MAX_ALTITUDE];

}

int SceneGraph::updateAltitude(Object *p_o, int new_alt) {

	if (!valueInRange(new_alt, 0, MAX_ALTITUDE)) {
		return -1;
	}

	if (!valueInRange(p_o->getAltitude(), 0, MAX_ALTITUDE)) {
		return -1;
	}

	visible_objects[level][p_o->getAltitude()].remove(p_o);
	visible_objects[level][new_alt].insert(p_o);

	return 0;

}

int SceneGraph::updateSolidness(Object *p_o, Solidness new_solidness) {

	if (p_o->isSolid()) {
		solid_objects[level].remove(p_o);
	}

	if (new_solidness == HARD || new_solidness == SOFT) {
		solid_objects[level].insert(p_o);
	}

	return 0;

}

int SceneGraph::setLevel(int new_level) {

	if (!valueInRange(new_level, 0, MAX_LEVEL)) {
		level = new_level;
		return 0;
	}

	else return -1;

}
int SceneGraph::getLevel() {

	return level;

}

int SceneGraph::updatePersistence(Object *p_o, bool new_persistence) {

	if (p_o->isPersistent() == new_persistence) {
		return -1;
	}

	int old_level, new_level;

	if (p_o->isPersistent()) {
		old_level = 0;
		new_level = level;
	}
	else {
		old_level = level;
		new_level = 0;
	}
	objects[old_level].remove(p_o);
	objects[new_level].insert(p_o);
	visible_objects[old_level][p_o->getAltitude()].remove(p_o);
	visible_objects[new_level][p_o->getAltitude()].insert(p_o);

	return 0;

}
