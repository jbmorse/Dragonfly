/*
 * GraphicsManager.cpp
 *
 *  Created on: Sep 22, 2013
 *      Author: Josh
 */

//Game engine header files
#include "GraphicsManager.h"
#include "LogManager.h"
#include "Utility.h"

//Misc required headers

GraphicsManager::GraphicsManager() {

	buffer = NULL;

}

GraphicsManager &GraphicsManager::getInstance() {

	static GraphicsManager graphicsManager;
	return graphicsManager;

}

int GraphicsManager::startUp() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("GraphicsManager::startUp: GraphicsManager starting\n");

	//Initialize screen
	initscr();
	buffer = newwin(0,0,0,0);
	werase(buffer);
	leaveok(buffer,TRUE);

	//If colors, add
	if (has_colors() == TRUE) {
		start_color();
		init_pair(COLOR_BLACK, COLOR_BLACK, COLOR_BLACK);
		init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);
		init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);
		init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
		init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);
		init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);
		init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
	}

	wattron(buffer, A_BOLD);

	is_started = true;
	return 0;

}

void GraphicsManager::shutDown() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("GraphicsManager::shutDown: Shutting down GraphicsManager\n");
	endwin();

}

int GraphicsManager::drawCh(Position pos, char ch, int color) {

	Position view_pos = worldToView(pos);
	wattron(buffer, COLOR_PAIR(color));
	mvwaddch(buffer, view_pos.getY(), view_pos.getX() , ch);
	wattroff(buffer, COLOR_PAIR(color));

	return 0;

}

int GraphicsManager::drawString(Position world_pos, string str, Justification just, int color) {

	Position start_pos = world_pos;

	switch(just) {

	case CENTER_JUSTIFIED:
		start_pos.setX(world_pos.getX() - str.size()/2);
		break;
	case RIGHT_JUSTIFIED:
		start_pos.setX(world_pos.getX() - str.size());
		break;
	case LEFT_JUSTIFIED:
	default:
		break;
	}

	Position *temp_pos = new Position();
	for (int i = 0; i < str.size(); i++) {
		temp_pos->setXY(start_pos.getX() + i, start_pos.getY());
		drawCh(*temp_pos, str[i], color);
	}

	return 0;

}

int GraphicsManager::drawFrame(Position world_pos, Frame frame,bool centered, int color) {

	string str = frame.getString();
	if (str == "") {
		return -1; //Empty frame
	}

	int x_offset, y_offset;
	if (centered) {
		x_offset = frame.getWidth() /2;
		y_offset = frame.getHeight() /2;
	}
	else {
		x_offset = 0;
		y_offset = 0;
	}
	int z = color;
	//Draw characters
	for (int y = 0; y < frame.getHeight(); y++) {
		for (int x = 0; x < frame.getWidth(); x++) {
			Position temp_pos(world_pos.getX() - x_offset + x, world_pos.getY() - y_offset + y);
			drawCh(temp_pos, str[y * frame.getWidth() + x], z);
		}
	}

	return 0;

}


int GraphicsManager::swapBuffers() {

	wrefresh(buffer);
	werase(buffer);

}

int GraphicsManager::getHorizontal() {

	int max_x, max_y;
	getmaxyx(buffer, max_y, max_x);
	return max_x;

}

int GraphicsManager::getVertical() {

	int max_x, max_y;
	getmaxyx(buffer, max_y, max_x);
	return max_y;

}

WINDOW *GraphicsManager::getBuffer() {

	return buffer;

}
