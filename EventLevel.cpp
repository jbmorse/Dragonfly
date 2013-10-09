/*
 * EventLevel.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

// Class include
#include "EventLevel.h"

EventLevel::EventLevel() {

	setType(LEVEL_EVENT);
	currentHashtag = "";

}

void EventLevel::setCurrentHashtag(string hash) {

	currentHashtag = hash;

}

string EventLevel::getCurrentHashtag() {

	return currentHashtag;

}

