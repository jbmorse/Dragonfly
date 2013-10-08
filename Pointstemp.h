/*
 * Pointstemp.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef POINTSTEMP_H_
#define POINTSTEMP_H_

#include "Event.h"
#include "ViewObject.h"

#define POINTS_STRING "Points"

class Pointstemp : public ViewObject {

	protected:
	int step_count;

	public:
	Pointstemp();
	int eventHandler(Event *p_e);

};

#endif /* POINTSTEMP_H_ */
