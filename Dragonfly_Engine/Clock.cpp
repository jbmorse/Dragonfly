/*
 * Clock.cpp
 *
 *  Created on: Sep 14, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Clock.h"

//Misc required headers
#include "time.h"

Clock::Clock() {

	clock_gettime(CLOCK_REALTIME, &prev_ts);

}

long int Clock::delta() {

	struct timespec post_ts;
	clock_gettime(CLOCK_REALTIME, &post_ts);

	long int beforemsec, aftermsec;
	beforemsec = prev_ts.tv_sec*1000 + prev_ts.tv_nsec/1000000;
	aftermsec = post_ts.tv_sec*1000 + post_ts.tv_nsec/1000000;

	prev_ts = post_ts; //This line differentiates delta() from split()

	return (aftermsec - beforemsec);

}

long int Clock::split() {

	struct timespec post_ts;
	clock_gettime(CLOCK_REALTIME, &post_ts);

	long int beforemsec, aftermsec;
	beforemsec = prev_ts.tv_sec*1000 + prev_ts.tv_nsec/1000000;
	aftermsec = post_ts.tv_sec*1000 + post_ts.tv_nsec/1000000;

	return (aftermsec - beforemsec);

}
