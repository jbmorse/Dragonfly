/*
 * Points.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventStep.h"
#include "GraphicsManager.h"
#include "Pointstemp.h"

Pointstemp::Pointstemp() {

	setLocation(TOP_RIGHT);
	setViewString(POINTS_STRING);
	setColor(COLOR_YELLOW);
	setPersistence(true);

	//Need to update score each second, so count "step" events
	registerInterest(STEP_EVENT);
	step_count = 0;

}

int Pointstemp::eventHandler(Event *p_e) {

	//Parent handles event if score update
	if (ViewObject::eventHandler(p_e)) {
		return 1;
	}

	//If step, increment score every second (30 steps)
	if (p_e->getType() == STEP_EVENT) {
		step_count++;
		if (step_count == 30) {	// 1 second has elapsed
			setValue(getValue() + 1);
			step_count = 0;
		}
	    return 1;
	  }

	//If we get here, we have ignored this event
	return 0;

}
