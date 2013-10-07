/*
 * Manager.h
 *
 *  Created on: Sep 10, 2013
 *      Author: Josh
 */

#ifndef MANAGER_H_
#define MANAGER_H_

//Game engine header files
#include "Object.h"
#include "ObjectList.h"

//Misc required headers
#include <string>

using std::string;

#define MAX_EVENTS 100		//Maximum number of different events

class Manager {

private:
	int event_count;
	string event_name[MAX_EVENTS];
	ObjectList obj_list[MAX_EVENTS];

protected:
	bool is_started;
	virtual bool isValid(string event_type);	//Check if event is handled by this manager

public:
	Manager();
	virtual ~Manager();
	virtual int startUp();	//Return 0 is successful, return negative if fail
	virtual void shutDown();//Stop Manager
	bool isStarted();		//Return true if started
	int registerInterest(Object *p_o, string event_type); 	//Indicate interest in event
	int unregisterInterest(Object *p_o, string event_type); //Remove interest in event
	void onEvent(Event *p_event);	//Send event to all interested Objects

};

#endif /* MANAGER_H_ */
