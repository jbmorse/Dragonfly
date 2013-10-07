/*
 * Event.h
 *
 *  Created on: Sep 16, 2013
 *      Author: Josh
 */

#ifndef EVENT_H_
#define EVENT_H_

//Game engine header files

//Misc required headers
#include <string>

using std::string;

#define UNDEFINED_EVENT "__undefined__"

class Event {

private:
	string event_type;		//Holds event type

public:
	Event();				//Create base event
	virtual ~Event();		//Destructor
	void setType(string new_type);	//Set event type
	string getType();				//Get event type

};

#endif /* EVENT_H_ */
