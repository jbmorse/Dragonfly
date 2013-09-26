/*
 * Position.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Position.h"
#include "LogManager.h"

//Misc required headers

Position::Position(int init_x, int init_y) {

	x = init_x;
	y = init_y;

}

Position::Position() {

	x = 0;
	y = 0;

}

int Position::getX() {

	return x;

}

void Position::setX(int new_x) {

	x = new_x;

}

int Position::getY() {

	return y;

}

void Position::setY(int new_y) {

	y = new_y;

}

void Position::setXY(int new_x, int new_y) {

	x = new_x;
	y = new_y;

}
