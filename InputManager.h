/*
 * InputManager.h
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

//Game engine header files
#include "Manager.h"

//Misc required headers

class InputManager : public Manager {

private:
	InputManager();							//Singleton
	InputManager (InputManager const&);		//No copying
	void operator=(InputManager const&);	//No assignment

public:
	static InputManager &getInstance();	//Grabs the singleton
	int startUp();						//Readies terminal for input
	void shutDown();					//Back to normal terminal mode
	bool isValid(string event_name);	//Only accepts keyboard and mouse events
	void getInput();					//Get input from the keyboard and mouse.

};

#endif /* INPUTMANAGER_H_ */
