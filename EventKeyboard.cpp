/*
 * EventKeyboard.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

//Game engine header files
#include "EventKeyboard.h"
#include "LogManager.h"

//Misc required headers

EventKeyboard::EventKeyboard() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("EventKeyboard::EventKeyboard: Made keyboard event\n");

	setType(KEYBOARD_EVENT);

	key_val = 0;

}

void EventKeyboard::setKey(int new_key) {

	key_val = new_key;

}

int EventKeyboard::getKey() {

	return key_val;

}
