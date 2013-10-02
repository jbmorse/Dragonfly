/*
 * Points.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef POINTS_H_
#define POINTS_H_

#include "Event.h"
#include "ViewObject.h"

#define POINTS_STRING "Points"

class Points : public ViewObject {

	protected:
	int step_count;

	public:
	Points();
	int eventHandler(Event *p_e);

};

#endif /* POINTS_H_ */
