/*
 * BossFinalIntro.h
 *
 *  Created on: Oct 12, 2013
 *      Author: Josh
 */

#ifndef BOSSFINALINTRO_H_
#define BOSSFINALINTRO_H_

#include "Object.h"
#include "ResourceManager.h"

/*
 * Used to introduce the final boss
 * POTENTIALLY NOT USED
 */
class BossFinalIntro : public Object {

	protected:
	int time_to_live;
	void step();

	public:
	BossFinalIntro();
	int eventHandler(Event *p_e);
};

#endif /* BOSSFINALINTRO_H_ */
