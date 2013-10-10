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
	levelEvent = "";
	levelEventNum = 0;

}

void EventLevel::setLevelEvent(string identifier) {

	levelEvent = identifier;

}

string EventLevel::getLevelEvent() {

	return levelEvent;

}

void EventLevel::setLevelEventNum(int num) {

	levelEventNum = num;

}

int EventLevel::getLevelEventNum() {

	return levelEventNum;

}
