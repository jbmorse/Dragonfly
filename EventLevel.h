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
	string currentHashtag;

public:
	EventLevel();
	string getCurrentHashtag();
	void setCurrentHashtag(string hash);

};


#endif /* EVENTLEVEL_H_ */
