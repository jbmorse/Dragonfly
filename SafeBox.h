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

class SafeBox : public Object {

	protected:
	void step();
	int time_to_live;

	public:
	SafeBox(Position position);
	int eventHandler(Event *p_e);
};

#endif /* SAFEBOX_H_ */
