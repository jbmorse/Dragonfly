/*
 * Star.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef STAR_H_
#define STAR_H_

#include "Object.h"

#define STAR_CHAR '.'

/*
 * This star object is used for special effects.
 * It is used in both the explosion animations and
 * in the hyperstar final boss fight mode.
 * This is a purely spectral object.
 */
class Star : public Object {

	private:
	void out();
	bool hyper;
	void step();
	int stepcount;

	public:
	Star();
	Star(Position position);
	void draw(void);
	int eventHandler(Event *p_e);
	void removeHyper();

};

#endif /* STAR_H_ */
