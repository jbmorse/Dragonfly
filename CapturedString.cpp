/*
 * CapturedString.cpp
 *
 *  Created: Oct 8, 2013
 *    Author: Tim
 */

// Class include
#include "CapturedString.h"
// Engine includes
#include "GraphicsManager.h"
#include "Utility.h"

CapturedString::CapturedString() {

}

int CapturedString::eventHandler(Event *p_e) {
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
