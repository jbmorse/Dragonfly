/*
 * Event.cpp
 *
 *  Created on: Sep 17, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Event.h"

//Misc required headers

Event::Event() {

	event_type = UNDEFINED_EVENT;

}

Event::~Event()	{

}

void Event::setType(string new_type) {

	event_type = new_type;

}
string Event::getType() {

	return event_type;

}
