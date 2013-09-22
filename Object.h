/*
 * Object.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef OBJECT_H_
#define OBJECT_H_

//Game engine header files
#include "Position.h"
#include "Event.h"

//Misc required headers
#include "string"

using std::string;

#define MAX_OBJ_EVENTS 30

class Object {

private:
	string type;	//User defined identification
	Position pos;	//Position in world
	int event_count;
	string event_name[MAX_OBJ_EVENTS];

public:
	Object();
	virtual ~Object();
	void setType(string new_type); 		//Set type identifier of object
	string getType();					//Get type identifier of object
	void setPosition(Position new_pos);	//Set position of object
	Position getPosition();				//Get position of object
	virtual int eventHandler(Event *p_e);//(0 if ignored, 1 otherwise)
	int registerInterest(string event_type);	//Add interest in event
	int unregisterInterest(string event_type);	//Remove interest in event

};


#endif /* OBJECT_H_ */
