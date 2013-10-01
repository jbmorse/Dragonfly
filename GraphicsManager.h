/*
 * GraphicsManager.h
 *
 *  Created on: Sep 22, 2013
 *      Author: Josh
 */

#ifndef GRAPHICSMANAGER_H_
#define GRAPHICSMANAGER_H_

#ifdef CYGWIN
#include <ncurses/curses.h>
#else
#include <curses.h>
#endif

//Game engine header files
#include "Manager.h"
#include "Position.h"
#include "Frame.h"

//Misc required headers

#define COLOR_DEFAULT COLOR_WHITE

enum Justification {
	LEFT_JUSTIFIED,
	CENTER_JUSTIFIED,
	RIGHT_JUSTIFIED,
};

class GraphicsManager : public Manager {

private:
	GraphicsManager();							//Private (singleton)
	GraphicsManager(GraphicsManager const&);	//No copying
	void operator=(GraphicsManager const&);		//No assignment
	WINDOW *buffer;

public:
	static GraphicsManager &getInstance();		//Get singleton
	int startUp();	//Get terminal ready for text-based display.
	void shutDown();
	int getHorizontal();		//Returns horizontal maximum
	int getVertical();			//Returns vertical maximum
	int swapBuffers();			//Render current display buffer
	WINDOW *getBuffer();		//Return drawing window

	int drawCh(Position world_pos,		//Draw char at pos
			char ch, int color = COLOR_DEFAULT);
	int drawString(Position world_pos,	//Draw string at pos, justified
			string str, Justification just, int color=COLOR_DEFAULT);
	int drawFrame(Position world_pos, 	//Draw frame at location
			Frame frame, bool centered, int color=COLOR_DEFAULT);

};

#endif /* GRAPHICSMANAGER_H_ */
