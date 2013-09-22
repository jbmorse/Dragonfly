/*
 * LogManager.h
 *
 *  Created on: Sep 10, 2013
 *      Author: Josh
 */

#ifndef LOGMANAGER_H_
#define LOGMANAGER_H_

//Game engine header files
#include "Manager.h"

//Misc required headers
#include "stdio.h"

#define LOGFILE_NAME "log.txt"

class LogManager : public Manager {

private:
	LogManager();						//Singleton constructor
	LogManager(LogManager const&);		//Prevents copying
	void operator=(LogManager const&);	//Prevents assignment
	bool do_flush;						//If true, fflush after each write
	FILE *p_f;							//Points to the log file

public:
	~LogManager();						//Singleton destructor
	static LogManager &getInstance();	//Retrieves the singleton
	int startUp(bool flush);			//Starts the LogManager (opens LOGFILE_NAME)
	void shutDown();					//Shuts down the LogManager
	int writeLog(const char *fmt, ...);	//Write to logfile, returns bytes written

};

#endif /* LOGMANAGER_H_ */
