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

/*
 * Characters are what the hero collects. They have their own character value.
 * Collecting the correct characters will add them to CapturedString.
 * Collecting the wrong characters will do nothing, they will simply be deleted.
 * Sometimes characters are used to do damage to boss characters.
 */
class Character : public Object {

	protected:
	void move();
	void out();
	void moveToStart();
	void hit(EventCollision *p_c);
	int stepcount;
	char chartype;

	public:
	Character();
	Character(char newchar);
	Character(bool spectral);
	~Character();
	int eventHandler(Event *p_e);
	void draw();
	char getChar();
	void setChar(char newchar);

  };


#endif /* CHARACTER_H_ */
