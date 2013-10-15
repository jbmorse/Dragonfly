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

Star::Star() {

	setType("Star");
	setSolidness(SPECTRAL);
	setXVelocity(random()%7 - 3);
	setYVelocity(random()%7 - 3);
	if (this->getXVelocity() == 0 && this->getYVelocity() == 0) {
		setXVelocity(5);
	}
	setAltitude(0);  //Make them in the background
	WorldManager &worldmanager = WorldManager::getInstance();
	Position pos(random()%worldmanager.getBoundary().getHorizontal(), random()%worldmanager.getBoundary().getVertical());
	setPosition(pos);

}

Star::Star(Position position) {

	setType("Star");
	setSolidness(SPECTRAL);
	setXVelocity(random()%7 - 3);
	setYVelocity(random()%7 - 3);
	if (this->getXVelocity() == 0 && this->getYVelocity() == 0) {
		setXVelocity(5);
	}
	setAltitude(0);  //Make them in the background
	WorldManager &worldmanager = WorldManager::getInstance();
	setPosition(position);

}

int Star::eventHandler(Event *p_e) {

	if (p_e->getType() == OUT_EVENT) {
		out();
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
	worldmanager.markForDelete(this);

 }


