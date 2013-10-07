/*
 * Clock.h
 *
 *  Created on: Sep 14, 2013
 *      Author: Josh
 */

#ifndef CLOCK_H_
#define CLOCK_H_

//Game engine header files

//Misc required headers
#include "time.h"

//Clock class used for timing
//Measures time in milliseconds
class Clock {

private:
	struct timespec prev_ts; //Stores the previous time delta() called

public:
	Clock(); //Sets prev_ts to current time
	long int delta(); //Return time elapsed since last delta()
	long int split(); //Return time elapsed since last delta()

};


#endif /* CLOCK_H_ */
