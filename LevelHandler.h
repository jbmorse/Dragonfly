/*
 * LevelHandler.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef LEVELHANDLER_H_
#define LEVELHANDLER_H_

#include "ViewObject.h"

class LevelHandler : public ViewObject {

private:
	void addLetter(char letter);
	int level;
	LevelHandler();

public:
	static LevelHandler &getInstance();
	int eventHandler(Event *p_e);
	void nextLevel(int nextlevel = 0);
	void restartGame();
	int getLevel();

};


#endif /* LEVELHANDLER_H_ */
