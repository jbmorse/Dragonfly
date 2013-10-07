/*
 * Box.cpp
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Box.h"

//Misc required headers

Box::Box() {

	horizontal = 0;
	vertical = 0;
	corner = Position(0,0);

}

Box::Box(Position init_corner, int init_horizontal, int init_vertical) {

	horizontal = init_horizontal;
	vertical = init_vertical;
	corner = init_corner;

}

Position Box::getCorner() {

	return corner;

}

void Box::setCorner(Position new_corner) {

	corner = new_corner;

}

int Box::getHorizontal() {

	return horizontal;

}

void Box::setHorizontal(int new_horizontal) {

	horizontal = new_horizontal;

}

int Box::getVertical() {

	return vertical;

}

void Box::setVertical(int new_vertical) {

	vertical = new_vertical;

}
