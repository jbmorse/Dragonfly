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
#include "LogManager.h"

//Misc required headers

InputManager::InputManager() {

	is_started = false;

}

InputManager &InputManager::getInstance() {

	static InputManager inputManager;
	return inputManager;

}

int InputManager::startUp() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("InputManager::startUp: InputManager starting\n");

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	if (!graphicsmanager.isStarted()) {
		return -1;
	}

	keypad(stdscr, TRUE);	//Enable keypad
	cbreak();				//Disable line buffering
	nonl();					//Turn off newline
	noecho();				//Disable echo
	curs_set(0);				//Turn off cursor
	nodelay(stdscr, TRUE);	//Set no delay
	mousemask(ALL_MOUSE_EVENTS, NULL);//Enable mouse events

	is_started = true;
	return 0;

}

void InputManager::shutDown() {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("InputManager::shutDown: Shutting down InputManager\n");
	curs_set(1);

}

bool InputManager::isValid(string event_name) {

	return (event_name == KEYBOARD_EVENT || event_name == MOUSE_EVENT);

}

void InputManager::getInput() {

	int c = getch();
	if (c != ERR) {
		MEVENT m_event;
		if (c == KEY_MOUSE) {
			getmouse(&m_event);
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

