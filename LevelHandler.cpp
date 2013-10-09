/*
 * LevelHandler.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */


// Class include
#include "CapturedString.h"
#include "LevelHandler.h"
#include "EventLevel.h"
// Engine includes
#include "GraphicsManager.h"
#include "Utility.h"

LevelHandler::LevelHandler() {

	setType("LevelHandler");
	registerInterest(LEVEL_EVENT);
	setLocation(TOP_LEFT);
	level = 1;

}

int LevelHandler::eventHandler(Event *p_e) {

	if(p_e->getType() == LEVEL_EVENT) {
		EventLevel *el = (EventLevel *) p_e;
		return 1;
	}

	return 0;
}

//TODO implement rest of levelHandler

