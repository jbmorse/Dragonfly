/*
 * ObjectListIterator.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "ObjectListIterator.h"

//Misc required headers
#include "stdio.h"

ObjectListIterator::ObjectListIterator(const ObjectList *p_l) {

		index = 0;
		p_list = p_l;

	}

ObjectListIterator::~ObjectListIterator() {

}

void ObjectListIterator::first() {

	index = 0;

}

void ObjectListIterator::next() {

	index++;

}

bool ObjectListIterator::isDone() {

	return (index == p_list->count);

}
Object* ObjectListIterator::currentObject() {

	return p_list->list[index];

}
