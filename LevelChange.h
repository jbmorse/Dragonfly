/*
 * GameOver.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef LEVELCHANGE_H_
#define LEVELCHANGE_H_

#include "ViewObject.h"

class LevelChange : public ViewObject {

	protected:
	int time_to_live;
	void step();
	int nextlevel;
	LevelChange();		//Should not have no next level

	public:
	LevelChange(int nextlevel);
	~LevelChange();
	int eventHandler(Event *e);
	void draw();
};



#endif /* LEVELCHANGE_H_ */
