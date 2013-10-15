/*
 * GameOver.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Josh
 */

#ifndef LEVELCHANGE_H_
#define LEVELCHANGE_H_

#include "ViewObject.h"

/*
 * Very important object for level changing! This displays the "goodjob!"
 * or "gameover!" or "youwin! sprite at the end of each level. This is created by
 * any win or lose condition present in each level.
 * Once this object hits 10 steps to completion, it will delete everything in the current level
 * Once it hits completion, it will go to the next level.
 */
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
