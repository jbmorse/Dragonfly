/*
 * EventCollision.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: Josh
 */

//Game engine header files
#include "EventCollision.h"
#include "LogManager.h"

//Misc required headers

EventCollision::EventCollision() {

	pos = Position();
	p_obj1 = NULL;
	p_obj2 = NULL;
	setType(COLLISION_EVENT);

}

EventCollision::EventCollision(Object *p_o1, Object *p_o2, Position p) {

	pos = p;
	p_obj1 = p_o1;
	p_obj2 = p_o2;
	setType(COLLISION_EVENT);

}

Object *EventCollision::getObject1() {

	return p_obj1;

}

void EventCollision::setObject1(Object *p_new_o1) {

	p_obj1 = p_new_o1;

}

Object *EventCollision::getObject2() {

	return p_obj2;

}

void EventCollision::setObject2(Object *p_new_o2) {

	p_obj2 = p_new_o2;

}

Position EventCollision::getPosition() {

	return pos;

}

void EventCollision::setPosition(Position new_pos) {

	pos = new_pos;

}

