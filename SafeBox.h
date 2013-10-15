/*
 * SafeBox.h
 *
 *  Created on: Oct 14, 2013
 *      Author: Josh
 */

#ifndef SAFEBOX_H_
#define SAFEBOX_H_

#include "Object.h"
#include "ResourceManager.h"

/*
 * This SafeBox object is placed in levels where it
 * runs the risk of killing the hero instantly.
 * It will disallow EvilCharacters from spawning in its zone.
 * It will disappear in one game loop upon start of level.
 */
class SafeBox : public Object {

	protected:
	void step();
	int time_to_live;

	public:
	SafeBox(Position position);
	int eventHandler(Event *p_e);
};

#endif /* SAFEBOX_H_ */
