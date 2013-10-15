/*
 * LevelHandler.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef LEVELHANDLER_H_
#define LEVELHANDLER_H_

#include "ViewObject.h"

/*
 * The LevelHandler is a persistent object that handles
 * level creation and level switching. Only GameStart and
 * LevelChange deal with this object directly. The methods for
 * the blueprints of each level can be found here. Checkpoints
 * are also set every time a certain level is reached, which can
 * be accessed and used by GameStart. This displays the level
 * in the top left corner of the game.
 */
class LevelHandler : public ViewObject {

private:
	void addLetter(char letter);
	int level;
	int checkpoint;
	LevelHandler();

public:
	static LevelHandler &getInstance();
	int eventHandler(Event *p_e);
	void nextLevel(int nextlevel = 0);
	void restartGame();
	int getLevel();
	int getCheckpoint();
	void setCheckpoint(int newcheckpoint);

};


#endif /* LEVELHANDLER_H_ */
