/*
 * EvilCharacter.h
 *
 *  Created on: Sep 3, 2013
 *      Author: Josh
 */

#ifndef EVILCHARACTER_H_
#define EVILCHARACTER_H_

#include "EventCollision.h"
#include "Object.h"

class EvilCharacter : public Object {

	protected:
	void move();
	void out();
	void moveToStart();
	void hit(EventCollision *p_c);
	string drawchar;
	int charnum;
	bool outIsDeath;
	bool tracksPlayer;
	int trackingTimeout;

	public:
	EvilCharacter(int charnumber, bool outIsDeath);
	~EvilCharacter();
	int eventHandler(Event *p_e);
	void draw();
	char getChar();
	void setTracksPlayer(bool newTracksPlayer);

  };


#endif /* EVILCHARACTER_H_ */
