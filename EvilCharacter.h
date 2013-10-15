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

/*
 * EvilCharacters are the things that kill the hero. The hero should avoid these
 * These can be stationary objects, they can move around, they can bounce, and
 * they can fly out of bounds and die. They are multi-use and in general
 * dangerous. Bosses shoot these. Some of them track the player.
 */
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
	EvilCharacter();
	~EvilCharacter();
	int eventHandler(Event *p_e);
	void draw();
	char getChar();
	void setTracksPlayer(bool newTracksPlayer);

  };


#endif /* EVILCHARACTER_H_ */
