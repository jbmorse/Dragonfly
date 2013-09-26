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

char *getTimeString();
//Return true if two positions intersect, else false.
bool positionsIntersect(Position p1, Position p2);


#endif /* UTILITY_H_ */
