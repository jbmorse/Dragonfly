/*
 * ViewEvent.cpp
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

//Game engine header files
#include "ViewEvent.h"

//Misc required headers

EventView::EventView() {

	tag = VIEW_EVENT;
	value = 0;
	delta = false;

}

EventView::EventView(string new_tag, int new_value, bool new_delta) {

	tag = new_tag;
	value = new_value;
	delta = new_delta;

}

void EventView::setTag(string new_tag) {

	tag = new_tag;

}

string EventView::getTag() {

	return tag;

}

void EventView::setValue(int new_value) {

	value = new_value;

}

int EventView::getValue() {

	return value;

}

void EventView::setDelta(bool new_delta) {

	delta = new_delta;

}

bool EventView::getDelta() {

	return delta;

}
