/*
 * Saucer.h
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#ifndef SAUCER_H_
#define SAUCER_H_

#include "EventCollision.h"
#include "Object.h"
#include "ResourceManager.h"

class Saucer : public Object {

	protected:
	void move();
	void out();
	void moveToStart();
	void hit(EventCollision *p_c);

	public:
	Saucer();
	~Saucer();
	int eventHandler(Event *p_e);


  };


#endif /* SAUCER_H_ */
