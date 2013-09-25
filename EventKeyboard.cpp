/*
 * EventKeyboard.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

//Game engine header files
#include "EventKeyboard.h"

//Misc required headers

EventKeyboard::EventKeyboard() {

	key_val = NULL;

}

void EventKeyboard::setKey(int new_key) {

	key_val = new_key;

}

int EventKeyboard::getKey() {

	return key_val;

}
