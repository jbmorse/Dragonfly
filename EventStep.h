/*
 * EventStep.h
 *
 *  Created on: Sep 17, 2013
 *      Author: Josh
 */

#ifndef EVENTSTEP_H_
#define EVENTSTEP_H_

//Game engine header files
#include "Event.h"

//Misc required headers
#include <string>

#define STEP_EVENT "__step__"

class EventStep : public Event {

public:
	EventStep();

};


#endif /* EVENTSTEP_H_ */
