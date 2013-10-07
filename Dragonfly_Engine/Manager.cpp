/*
 * Manager.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Manager.h"
#include "ObjectListIterator.h"
#include "EventView.h"
#include "LogManager.h"

//Misc required headers
#include "stdio.h"

Manager::Manager() {

	is_started = false;
	event_count = 0;

}

Manager::~Manager() {

}

//Start Manager
//Return 0 is successful, return negative if fail
int Manager::startUp() {

	is_started = true;
	return 0;

}

void Manager::shutDown() {

	is_started = false;

}

bool Manager::isStarted() {

	return is_started;

}

int Manager::registerInterest(Object *p_o, string event_type) {

	for (int i = 0; i < event_count; i++) {
		if (event_name[i] == event_type) {
			obj_list[i].insert(p_o);
			return 0; //Interested
		}
	}

	//This is new event
	if (event_count >= MAX_EVENTS) {
		return -1; //List is full
	}

	event_name[event_count] = event_type;
	obj_list[event_count].insert(p_o);
	event_count++;

	return 0;

}

int Manager::unregisterInterest(Object *p_o, string event_type) {

	int i;
	for (i = 0; i < event_count; i++) {
		if (event_name[i] == event_type) {
			obj_list[i].remove(p_o);
			break;
		}
	}

	if (obj_list[i].isEmpty()) {
		//Empty list, time for scooting!
		for (; i < event_count; i++) {
			obj_list[i] = obj_list[i+1];
			event_name[i] = event_name[i+1];
		}
		event_count--;
		return 0;
	}

	return 0;

}

void Manager::onEvent(Event *p_event) {

	for (int i = 0; i < event_count; i++) {
		if (event_name[i] == p_event->getType()) {
			ObjectListIterator iterator = ObjectListIterator(&(obj_list[i]));
			while (!iterator.isDone()) {
				iterator.currentObject()->eventHandler(p_event);
				iterator.next();
			}
		}
	}

}

bool Manager::isValid(string event_name) {

	return false;

}
