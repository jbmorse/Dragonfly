/*
 * ViewObject.cpp
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

//Game engine header files
#include "ViewObject.h"
#include "Utility.h"
#include "EventView.h"
#include "GraphicsManager.h"
#include "WorldManager.h"
#include "LogManager.h"

//Misc required headers

ViewObject::ViewObject() {

	//Initialize Object attributes
	setSolidness(SPECTRAL);
	setAltitude(MAX_ALTITUDE);
	setType("ViewObject");

	//Initialize ViewObject attributes
	setValue(0);
	setBorder(true);
	setLocation(TOP_CENTER);
	setColor(COLOR_DEFAULT);
	setAltitude(0);

	//Register interest for view events
	registerInterest(VIEW_EVENT);

}

void ViewObject::draw() {

	string temp_str;
	if (border) {
		temp_str = (" " + getViewString() + " " + intToString(value) + " ");
	}
	else {
		temp_str = (getViewString() + " " + intToString(value));
	}

	//Draw centered at position
	Position pos = worldToView(getPosition());
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawString(pos, temp_str, CENTER_JUSTIFIED, getColor());

	if (border) {
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

int ViewObject::eventHandler(Event *p_e) {

	// See if this is a `view' event.
	if (p_e->getType() == VIEW_EVENT) {
		EventView *p_ve = (EventView *) p_e;
		if (p_ve->getTag() == getViewString()) {
			if (p_ve->getDelta()) {
				setValue(getValue() + p_ve->getValue()); //Change in value
			}
			else {
				setValue(p_ve->getValue());		//New value
			}
			return 1;
		}
	}

	return 0;

}

void ViewObject::setLocation(ViewObjectLocation new_location) {

	WorldManager &worldmanager = WorldManager::getInstance();

	Position p = getPosition();

	int delta = 0;
	//Set new position based on location
	switch (new_location) {
	case TOP_LEFT:
		p.setXY(worldmanager.getView().getHorizontal() * 1/6, 1);
		if (!getBorder()) {
			delta = -1;
		}
		break;
	case TOP_CENTER:
		p.setXY(worldmanager.getView().getHorizontal() * 3/6, 1);
		if (!getBorder()) {
			delta = -1;
		}
		break;
	case TOP_RIGHT:
		p.setXY(worldmanager.getView().getHorizontal() * 5/6, 1);
		if (!getBorder()) {
			delta = -1;
		}
		break;
	case BOTTOM_LEFT:
		p.setXY(worldmanager.getView().getHorizontal() * 1/6,
				worldmanager.getView().getVertical() - 1);
		if (!getBorder()) {
			delta = 1;
		}
		break;
	case BOTTOM_CENTER:
		p.setXY(worldmanager.getView().getHorizontal() * 3/6,
				worldmanager.getView().getVertical() - 1);
		if (!getBorder()) {
			delta = 1;
		}
		break;
	case BOTTOM_RIGHT:
		p.setXY(worldmanager.getView().getHorizontal() * 5/6,
				worldmanager.getView().getVertical() - 1);
		if (!getBorder()) {
			delta = 1;
		}
		break;

	}

	//Shift, as needed, based on border
	p.setY(p.getY() + delta);
	setPosition(p);

}

void ViewObject::setValue(int new_value) {

	value = new_value;

}

int ViewObject::getValue() {

	return value;

}

void ViewObject::setBorder(bool new_border) {

	border = new_border;

}

bool ViewObject::getBorder() {

	return border;

}

void ViewObject::setColor(int new_color) {

	color = new_color;

}

int ViewObject::getColor() {

	return color;

}

void ViewObject::setViewString(string new_view_string) {

	view_string = new_view_string;

}

string ViewObject::getViewString() {

	return view_string;

}
