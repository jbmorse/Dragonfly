/*
 * Object.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Object.h"
#include "Position.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "GameManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "InputManager.h"

//Misc required headers

Object::Object() {

	altitude = 0;
	event_count = 0;
	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Object::Object: Creating Object\n");
	type = "Object";
	pos = Position();
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.insertObject(this);

}

Object::~Object() {

	for (int i = event_count; i > 0; i--) {
		unregisterInterest(event_name[i]);
	}
	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Object::~Object: Destroying Object\n");
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.removeObject(this);

}

void Object::setType(string new_type) {

	type = new_type;

}

string Object::getType() {

	return type;

}

void Object::setPosition(Position new_pos) {

	pos = new_pos;

}

Position Object::getPosition() {

	return pos;

}

int Object::eventHandler(Event *p_e) {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Object::eventHandler: Object received event!\n");

	//For now all objects will move to the right when they receive an event (to be removed)
	if (p_e->getType() == STEP_EVENT) {
		this->setPosition(Position(pos.getX() + 1,pos.getY()));
		logmanager.writeLog("Object::eventHandler: Object set position (%d, %d)!\n", pos.getX(), pos.getY());
	}
	return 1;

}

int Object::registerInterest(string event_type) {

	if (event_count == MAX_OBJ_EVENTS) {
		return -1;
	}

	if (event_type == STEP_EVENT) {
		GameManager &gamemanager = GameManager::getInstance();
		gamemanager.registerInterest(this, event_type);
	}
	else if (event_type == MOUSE_EVENT || event_type == KEYBOARD_EVENT) {
		InputManager &inputmanager = InputManager::getInstance();
		inputmanager.registerInterest(this, event_type);
	}
	else {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.registerInterest(this, event_type);
	}

	event_name[event_count] = event_type;
	event_count++;

	return 0;

}

int Object::unregisterInterest(string event_type) {

	if (event_type == STEP_EVENT) {
		GameManager &gamemanager = GameManager::getInstance();
		gamemanager.unregisterInterest(this, event_type);
	}
	else if (event_type == MOUSE_EVENT || event_type == KEYBOARD_EVENT) {
		InputManager &inputmanager = InputManager::getInstance();
		inputmanager.unregisterInterest(this, event_type);
	}
	else {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.unregisterInterest(this, event_type);
	}

	for (int i = 0; i < event_count; i++) {
		if (event_name[i] == event_type) {
			for (; i < event_count-1; i++) {
				event_name[i] = event_name[i+1];
			}
		}
	}

	event_count--;
	return 0;

}

void Object::draw() {

}

int Object::setAltitude(int new_altitude) {

	if (new_altitude >= 0 && new_altitude <= MAX_ALTITUDE) {
		altitude = new_altitude;
		return 0;
	}

	return -1;

}

int Object::getAltitude() {

	return altitude;

}
