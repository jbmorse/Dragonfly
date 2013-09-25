/*
 * InputManager.cpp
 *
 *  Created on: Sep 24, 2013
 *      Author: Josh
 */

//Game engine header files
#include "InputManager.h"
#include "GraphicsManager.h"
#include "EventKeyboard.h"
#include "EventMouse.h"
#include "Manager.h"

//Misc required headers

InputManager::InputManager() {

	is_started = false;

}

InputManager &InputManager::getInstance() {

	static InputManager inputManager;
	return inputManager;

}

int InputManager::startUp() {

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	if (!graphicsmanager.isStarted()) {
		return -1;
	}

	int success = 0;

	success += keypad(stdscr, TRUE);	//Enable keypad
	success += cbreak();				//Disable line buffering
	success += nonl();					//Turn off newline
	success += noecho();				//Disable echo
	success += curs_set(0);				//Turn off cursor
	success += nodelay(stdscr, TRUE);	//Set no delay
	success += mousemask(BUTTON1_CLICKED, NULL);//Enable mouse events

	if (success == 0) {
		Manager::startUp();
		return 0;
	}
	else return -1;

}

void InputManager::shutDown() {

	curs_set(1);
	Manager::shutDown();

}

bool InputManager::isValid(string event_name) {

	return (event_name == KEYBOARD_EVENT || event_name == MOUSE_EVENT);

}

void InputManager::getInput() {

	int c = getch();
	if (c != ERR) {
		MEVENT m_event;
		if ((c == KEY_MOUSE) && getmouse(&m_event)) {
			if (m_event.bstate & BUTTON1_CLICKED) {
				EventMouse mouseEvent = EventMouse();
				mouseEvent.setMouseX(m_event.x);
				mouseEvent.setMouseY(m_event.y);
				onEvent(&mouseEvent);
			}
		}
		//Keyboard input
		else {
			EventKeyboard keyEvent = EventKeyboard();
			keyEvent.setKey(c);
			onEvent(&keyEvent);
		}
	}

}

