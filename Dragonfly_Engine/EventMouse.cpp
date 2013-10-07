/*
 * EventMouse.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

//Game engine header files
#include "EventMouse.h"

//Misc required headers

EventMouse::EventMouse() {

	mouse_action = UNDEFINED;
	mouse_x = 0;
	mouse_y = 0;
	setType(MOUSE_EVENT);

}

void EventMouse::setMouseAction(enum MouseActionList new_action) {

	mouse_action = new_action;

}

enum MouseActionList EventMouse::getMouseAction() {

	return mouse_action;

}

void EventMouse::setMouseX(int new_x) {

	mouse_x = new_x;

}

void EventMouse::setMouseY(int new_y) {

	mouse_y = new_y;

}

int EventMouse::getMouseX() {

	return mouse_x;

}

int EventMouse::getMouseY() {

	return mouse_y;

}
