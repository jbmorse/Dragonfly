/*
 * ObjectListIterator.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef OBJECTLISTITERATOR_H_
#define OBJECTLISTITERATOR_H_

//Game engine header files
#include "ObjectList.h"

//Misc required headers

class ObjectList;

class ObjectListIterator {

private:
	ObjectListIterator();		//Must be given list when created
	int index;					//Index into list
	const ObjectList *p_list;	//List iterating over

public:
	~ObjectListIterator();
	ObjectListIterator(const ObjectList *p_l);	//Create iterator over indicated list
	void first(); 	//Set iterator to first item
	void next();	//Set iterator to next item
	bool isDone(); 	//Return true if at end of list
	Object *currentObject(); //Return pointer to current Object

};

#endif /* OBJECTLISTITERATOR_H_ */
