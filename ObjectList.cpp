/*
 * ObjectList.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "ObjectList.h"
#include "LogManager.h"

//Misc required headers

ObjectList::ObjectList() {

	count = 0;
	for (int i = 0; i < MAX_OBJECTS; i++) {
		list[i] = NULL;
	}

}

ObjectList::~ObjectList() {

}

ObjectListIterator ObjectList::createIterator() const {

	return ObjectListIterator(this);

}

int ObjectList::insert(Object *p_o) {

	if (count < 5000) {
		list[count] = p_o;
		count++;
		return 0;
	}

	return -1; //List full

}

int ObjectList::remove(Object *p_o) {

	for (int i = 0; i < count; i++) {
		if (list[i] == p_o) {
			for (; i < count-1; i++) {
				list[i] = list[i+1];
			}
			list[i+1] = NULL;
			count--;
			return 0;
		}
	}

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("ObjectList::remove: Did not locate object!\n");

	return -1; //Did not locate object

}

void ObjectList::clear() {

	for (int i = 0; i < count; i++) {
		list[i] = NULL;
	}
	count = 0;

}

int ObjectList::getCount() {

	return count;

}

bool ObjectList::isEmpty() {

	return (count == 0);

}

bool ObjectList::isFull() {

	return (count == 5000);

}
