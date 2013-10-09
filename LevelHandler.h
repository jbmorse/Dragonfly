/*
 * LevelHandler.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef LEVELHANDLER_H_
#define LEVELHANDLER_H_

class LevelHandler : public ViewObject {

private:
	void addLetter(char letter);
	int level;

public:
	LevelHandler();
	int eventHandler(Event *p_e);
	void draw();
	void nextLevel();

};


#endif /* LEVELHANDLER_H_ */
