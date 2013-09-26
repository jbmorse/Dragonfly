/*
 * Character.h
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "EventCollision.h"
#include "Object.h"

class Character : public Object {

	protected:
	void move();
	void out();
	void moveToStart();
	void hit(EventCollision *p_c);
	int stepcount;
	char drawchar;

	public:
	Character();
	~Character();
	int eventHandler(Event *p_e);
	void draw();

  };


#endif /* CHARACTER_H_ */
