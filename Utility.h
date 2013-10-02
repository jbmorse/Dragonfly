/*
 * Utility.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef UTILITY_H_
#define UTILITY_H_


#define DEBUG_1 ; //If defined, will print out debug information to log file

//Game engine header files
//Misc required headers

//Returns a very nicely formatted time string - HH:MM:SS
char *getTimeString();

//Return true if two positions intersect, else false
bool positionsIntersect(Position p1, Position p2);

//Return true if boxes intersect, else false
bool boxIntersectsBox(Box A, Box B);

//Return true if value is between min and max (inclusive).
bool valueInRange(int value, int min, int max);

//Convert relative bounding Box for Object to absolute world Box
Box getWorldBox(Object *p_o);

//Return distance between any two Points
float distance(Position p1, Position p2);

//Return true of Point is within Box
bool boxContainsPoint(Box b, Position p);

#endif /* UTILITY_H_ */
