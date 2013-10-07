/*
 * LogManager.cpp
 *
 *  Created on: Sep 10, 2013
 *      Author: Josh
 */

//Game engine header files
#include "LogManager.h"
#include "Utility.h"

//Misc required headers
#include "stdio.h"
#include "stdarg.h"
#include "iostream"

LogManager::LogManager() {

	p_f = NULL;
	do_flush = true;

}

LogManager::~LogManager() {

}

LogManager &LogManager::getInstance() {

	static LogManager logManager;
	return logManager;

}

int LogManager::startUp(bool flush=false) {

	bool do_flush = flush;
	FILE* p_f = freopen(LOGFILE_NAME, "w", stderr);
	if (p_f != NULL) return 0; //Success
	else return -1; //Failure

}

void LogManager::shutDown() {

	writeLog("LogManager::shutDown: Log Manager shutting down\n");
	fclose(p_f);
	Manager::shutDown();

}

int LogManager::writeLog(const char *fmt, ...) {

	int bytes;
	fprintf(stderr, "%s Message: ", getTimeString());
	va_list args;
	va_start(args, fmt);
	bytes = vfprintf(stderr, fmt, args);
	va_end(args);
	if (do_flush) fflush(stderr);

	return bytes;

}
