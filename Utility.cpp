/*
 * Utility.cpp
 *
 *  Created on: Sep 13, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Position.h"
#include "Box.h"
#include "Object.h"

//Misc required headers
#include "time.h"
#include "stdio.h"
#include "cstdlib"

char *getTimeString() {

	//String that will be returned
	static char time_str[30];

	time_t rawtime;
	struct tm * timeinfo;

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	sprintf(time_str, "%02d:%02d:%02d", timeinfo -> tm_hour, timeinfo -> tm_min, timeinfo -> tm_sec);

	return time_str;

}

bool positionsIntersect(Position p1, Position p2) {

	return ((p1.getX() == p2.getX()) && p1.getY() == p2.getY());

}

bool valueInRange(int value, int min, int max) {

	return (min <= value && value <= max);

}

bool boxIntersectsBox(Box A, Box B) {

	//Test horizontal overlap
	bool x_overlap =
			//Left side of A in B?
		((valueInRange(A.getCorner().getX(), B.getCorner().getX(),
				B.getCorner().getX() + B.getHorizontal()-1)) ||
			//Left side of B in A?
		(valueInRange(B.getCorner().getX(), A.getCorner().getX(),
				A.getCorner().getX() + A.getHorizontal()-1)));

	//Test vertical overlap
	bool y_overlap =
			//Top side of A in B?
		((valueInRange(A.getCorner().getY(), B.getCorner().getY(),
				B.getCorner().getY() + B.getVertical()-1)) ||
			//Top side of B in A?
		(valueInRange(B.getCorner().getY(), A.getCorner().getY(),
				A.getCorner().getY() + A.getVertical()-1)));

	return (x_overlap && y_overlap);

}

Box getWorldBox(Object *p_o) {

	Box temp_box = p_o->getBox();
	Position corner = temp_box.getCorner();
	corner.setX(corner.getX() + p_o->getPosition().getX());
	corner.setY(corner.getY() + p_o->getPosition().getY());
	temp_box.setCorner(corner);

	return temp_box;

}

//Return distance between any two Points
float distance(Position p1, Position p2) {

	return (abs(p1.getX() - p2.getX()) + abs(p1.getY() + p2.getY()));

}

//Return true of Point is within Box
bool boxContainsPoint(Box b, Position p) {

	return (valueInRange(p.getX(),
		b.getCorner().getX(), b.getCorner().getX() + b.getHorizontal()-1) &&
			(valueInRange(p.getY(),
		b.getCorner().getY(), b.getCorner().getY() + b.getVertical()-1)));

}
