/*
 * ViewEvent.h
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

#ifndef VIEWEVENT_H_
#define VIEWEVENT_H_

//Game engine header files
#include "Event.h"

//Misc required headers

#define VIEW_EVENT "__view__"

class EventView : public Event {

private:
	string tag;  //Tag to associate
	int value;   //Value for view
	bool delta;  //True if change in value, else replace value

public:
	EventView();						//Create view event
	EventView(string new_tag, int new_value, bool new_delta);
	void setTag(string new_tag);		//Set tag
	string getTag();					//Get tag
	void setValue(int new_value);		//Set value
	int getValue();						//Get value
	void setDelta(bool new_delta);		//Set delta
	bool getDelta(); 					//Get delta

};

#endif /* VIEWEVENT_H_ */
