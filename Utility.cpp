/*
 * Utility.cpp
 *
 *  Created on: Sep 13, 2013
 *      Author: Josh
 */

//Game engine header files
//Misc required headers
#include "time.h"
#include "stdio.h"

//Returns a very nicely formatted time string - HH:MM:SS
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
