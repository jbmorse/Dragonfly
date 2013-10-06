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

class Star : public Object {

	private:
	void out();

	public:
	Star();
	void draw(void);
	int eventHandler(Event *p_e);

};

#endif /* STAR_H_ */
