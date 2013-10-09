/*
 * GameStart.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef GAMESTART_H_
#define GAMESTART_H_

#include "ViewObject.h"

#define PLAY_LEVEL 2
#define MENU_LEVEL 1

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
