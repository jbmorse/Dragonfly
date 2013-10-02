/*
 * GameOver.h
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#ifndef GAMEOVER_H_
#define GAMEOVER_H_

#include "ViewObject.h"

class GameOver : public ViewObject {

	protected:
	int time_to_live;
	void step();

	public:
	GameOver();
	~GameOver();
	int eventHandler(Event *e);
	void draw();
};



#endif /* GAMEOVER_H_ */
