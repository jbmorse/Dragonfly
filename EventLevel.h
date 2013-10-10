/*
 * EventLevel.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef EVENTLEVEL_H_
#define EVENTLEVEL_H_

// Engine includes
#include "Event.h"

#define LEVEL_EVENT "_level_"

class EventLevel : public Event {

private:
	string levelEvent;
	int levelEventNum;

public:
	EventLevel();
	string getLevelEvent();
	void setLevelEvent(string identifier);
	int getLevelEventNum();
	void setLevelEventNum(int num);

};


#endif /* EVENTLEVEL_H_ */
