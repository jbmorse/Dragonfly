/*
 * ObjectList.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef OBJECTLIST_H_
#define OBJECTLIST_H_

#define MAX_OBJECTS 5000

//Game engine header files
#include "Object.h"
#include "ObjectListIterator.h"

//Misc required headers

class ObjectListIterator;

class ObjectList {

private:
	int count;					//Count of objects in list
	Object *list[MAX_OBJECTS];	//Array of pointers to objects

public:
	friend class ObjectListIterator;
	ObjectListIterator createIterator() const;
	ObjectList();
	~ObjectList();
	int insert(Object *p_o);	//Insert object, return 0 if OK
	int remove(Object *p_o);	//Remove object, return 0 if found
	void clear();				//Clear list
	int getCount();				//Return number of objects in list
	bool isEmpty();				//Return true if list is empty
	bool isFull(); 				//Return true if list is full

};

#endif /* OBJECTLIST_H_ */
