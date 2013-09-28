/*
 * EventMouse.h
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

#ifndef EVENTMOUSE_H_
#define EVENTMOUSE_H_

//Game engine header files
#include "Event.h"

//Misc required headers

#define MOUSE_EVENT "__mouse__"

//The set of recognized mouse actions
enum MouseActionList {
	LEFT_BUTTON_CLICK,
	LEFT_BUTTON_DOUBLECLICK,
	RIGHT_BUTTON_CLICK,
	RIGHT_BUTTON_DOUBLECLICK,
	UNDEFINED
};

class EventMouse : public Event {

private:
	enum MouseActionList mouse_action;	//Mouse action
	int mouse_x;						//The x coordinate
	int mouse_y;						//The y coordinate

public:
	EventMouse();
	void setMouseAction(enum MouseActionList new_action);	//Load action
	enum MouseActionList getMouseAction();					//Get action
	void setMouseX(int new_x);								//Set X
	void setMouseY(int new_y);								//Set Y
	int getMouseX();										//Get X
	int getMouseY();										//Get Y

};

#endif /* EVENTMOUSE_H_ */
