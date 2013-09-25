/*
 * EventKeyboard.h
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

#ifndef EVENTKEYBOARD_H_
#define EVENTKEYBOARD_H_

//Game engine header files
#include "Event.h"

//Misc required headers

#define KEYBOARD_EVENT "__keyboard__"

class EventKeyboard : public Event {

private:
	int key_val; //Stores key value

public:
	EventKeyboard();
	void setKey(int new_key);	//Set key in event
	int getKey();				//Get key from event

};



#endif /* EVENTKEYBOARD_H_ */
