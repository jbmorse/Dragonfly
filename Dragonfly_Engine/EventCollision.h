/*
 * EventCollision.h
 *
 *  Created on: Sep 25, 2013
 *      Author: Josh
 */

#ifndef EVENTCOLLISION_H_
#define EVENTCOLLISION_H_

//Game engine header files
#include "Event.h"
#include "Object.h"

//Misc required headers

#define COLLISION_EVENT "__collision__"

class EventCollision : public Event {

private:
	Position pos;   //Where collision occurred
	Object *p_obj1; //Caused collision
	Object *p_obj2; //Object being collided with

public:
	EventCollision();	//Create collision event at (0,0) with obj1 and obj2 NULL
	EventCollision(Object *p_o1, Object *p_o2, Position p);
	Object *getObject1();					//Get object that caused collision
	void setObject1(Object *p_new_o1);		//Set object that caused collision
	Object *getObject2();					//Get object that was collided with
	void setObject2(Object *p_new_o2);		//Set object that was collided with
	Position getPosition();					//Get position of collision
	void setPosition(Position new_pos);		//Set position of collision

};

#endif /* EVENTCOLLISION_H_ */
