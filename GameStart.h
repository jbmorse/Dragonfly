/*
 * GameStart.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef GAMESTART_H_
#define GAMESTART_H_

#include "ViewObject.h"

/*
 * Object that controls the level selection by the player.
 * This resides in level 1 (the menu).
 */
class GameStart : public ViewObject {

	protected:
	void step();
	void start();

	public:
	GameStart();
	int eventHandler(Event *e);
	void draw();

};

#endif /* GAMESTART_H_ */
