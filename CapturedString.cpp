/*
 * CapturedString.cpp
 *
 *  Created: Oct 8, 2013
 *    Author: Tim
 */

// Class include
#include "CapturedString.h"
// System includes
#include <algorithm>
// Engine includes
#include "LevelHandler.h"
#include "EventCapturedLetter.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "Utility.h"
#include "LogManager.h"
#include "LevelChange.h"
#include "WorldManager.h"

CapturedString::CapturedString() {

	setType("CapturedString");
	registerInterest(CAPTURED_LETTER_EVENT);
	setLocation(TOP_CENTER);
}

CapturedString::CapturedString(string new_complete_string) {
	setType("CapturedString");
	registerInterest(CAPTURED_LETTER_EVENT);
	setLocation(TOP_CENTER);

	complete_string.resize(new_complete_string.length());
	transform(new_complete_string.begin(),
		new_complete_string.end(), complete_string.begin(), toupper);
	setViewString(string(complete_string.length(), ' '));
}

int CapturedString::eventHandler(Event *p_e) {

	if(p_e->getType() == CAPTURED_LETTER_EVENT) {
		EventCapturedLetter *ecl = (EventCapturedLetter *) p_e;
		addLetter(ecl->getCapturedLetter());
		return 1;
	}

	return 0;
}

void CapturedString::draw() {

	string temp_str;
	if (getBorder()) {
		temp_str = (" " + getViewString() + " ");
	}
	else {
		temp_str = (getViewString());
	}

	//Draw centered at position
	Position pos = worldToView(getPosition());
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());

	if (getBorder()) {
		string top_border = "";
		char side_border = '|';
		for (int i = 0; i < temp_str.length(); i++) {
			top_border += "-";
		}
		Position bottom_pos = Position(pos.getX(), pos.getY() + 1);
		Position top_pos = Position(pos.getX(), pos.getY() - 1);
		Position left_border = Position(pos.getX() - temp_str.length()/2 - 1, pos.getY());
		Position right_border = Position(pos.getX() + temp_str.length()/2 + 1, pos.getY());
		graphicsmanager.drawString(top_pos, top_border, CENTER_JUSTIFIED, getColor());
		graphicsmanager.drawString(bottom_pos, top_border, CENTER_JUSTIFIED, getColor());
		graphicsmanager.drawCh(left_border, side_border, getColor());
		graphicsmanager.drawCh(right_border, side_border, getColor());

	}
}

void CapturedString::addLetter(char letter) {
	string temp_str = getViewString();

	// Handle wildcard
	if(letter == '*') {

		int firstEmptyPos = 0;
		for(int i = 0; i < temp_str.length(); ++i) {
			if(temp_str[i] == ' ') {
				firstEmptyPos = i;
				break;
			}
		}

		// Add letter
		temp_str[firstEmptyPos] = complete_string[firstEmptyPos];
	} else {
		// Normal character
		size_t posInCompleteString = complete_string.find_first_of(letter, 0);

		if(posInCompleteString == string::npos) 
			return; // character isn't in string, ignore

		do {
			if(temp_str[posInCompleteString] == letter)
				continue; // already got this one
			// else

			temp_str[posInCompleteString] = letter;
			break; // done

		} while((posInCompleteString = complete_string.find_first_of(letter,
			 posInCompleteString + 1)) != string::npos);
		// loop until there are no more instances of this character in the string
	}

	setViewString(temp_str);

	if(temp_str == complete_string) { // completed string
		LogManager &logmanager = LogManager::getInstance();
		logmanager.writeLog("Completed string!\n");

		//Level over, make hero spectral
		WorldManager &worldmanager = WorldManager::getInstance();
		ObjectList objects_copy = worldmanager.getAllObjects();
		ObjectListIterator i(&objects_copy);
		for (i.first(); !i.isDone(); i.next()) {
			if (i.currentObject()->getType().compare("Hero") == 0) {
				i.currentObject()->setSolidness(SPECTRAL);
			}
		}

		LevelHandler &levelhandler = LevelHandler::getInstance();
		new LevelChange(levelhandler.getLevel() + 1);

	}
}

void CapturedString::setCompleteString(string new_complete_string) {
	complete_string.resize(new_complete_string.length());
	transform(new_complete_string.begin(),
		new_complete_string.end(), complete_string.begin(), toupper);
}

string CapturedString::getCompleteString() {
	return complete_string;
}
