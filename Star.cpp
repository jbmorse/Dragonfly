/*
 * Star.cpp
 *
 *  Created on: Sep 4, 2013
 *      Author: Josh
 */

#include "EventOut.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "Star.h"
#include "Stdlib.h"
#include "WorldManager.h"
#include "EventStep.h"

Star::Star() {

	//HYPER star constructor

	setType("Star");
	setSolidness(SPECTRAL);
	setXVelocity(-0.5 / (random()%7 + 1));
	setAltitude(4);  //Make them in the background
	WorldManager &worldmanager = WorldManager::getInstance();
	Position pos(random()%worldmanager.getBoundary().getHorizontal() + 20, random()%worldmanager.getBoundary().getVertical());
	setPosition(pos);
	hyper = true;
	stepcount = 0;

	//Step to speed up
	registerInterest(STEP_EVENT);

}

Star::Star(Position position) {

	setType("Star");
	setSolidness(SPECTRAL);
	setXVelocity(random()%7 - 3);
	setYVelocity(random()%7 - 3);
	if (this->getXVelocity() == 0 && this->getYVelocity() == 0) {
		setXVelocity(5);
	}
	setAltitude(4);  //Make them in the background
	WorldManager &worldmanager = WorldManager::getInstance();
	setPosition(position);
	hyper = false;
	stepcount = 0;

}

int Star::eventHandler(Event *p_e) {

	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}
	if (p_e->getType() == STEP_EVENT) {
		step();
		return 1;
	}

    return 0;

}


void Star::draw() {

	GraphicsManager &graph_mgr = GraphicsManager::getInstance();
	graph_mgr.drawCh(getPosition(), STAR_CHAR);

}

//If star moved off screen, move back to far right
void Star::out() {

	WorldManager &worldmanager = WorldManager::getInstance();

	if (!hyper) {
		worldmanager.markForDelete(this);
	}
	else {
		Position pos(worldmanager.getBoundary().getHorizontal() + random()%20, random() % worldmanager.getBoundary().getVertical());
		setPosition(pos);
	}

}

void Star::step() {

	stepcount++;
	if (stepcount < 60) {
		setXVelocity(getXVelocity() - (.05 / (random() % 5+1)));
	}

}

void Star::removeHyper() {

	hyper = false;

}

