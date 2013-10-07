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
	setXVelocity(-1.0 / (random()%10 + 1));
	setAltitude(0);  //Make them in the background
	WorldManager &worldmanager = WorldManager::getInstance();
	Position pos(random()%worldmanager.getBoundary().getHorizontal(), random()%worldmanager.getBoundary().getVertical());
	setPosition(pos);

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
	Position pos(worldmanager.getBoundary().getHorizontal() + random()%20, random() % worldmanager.getBoundary().getVertical());
	setPosition(pos);
	setXVelocity(-1.0 / (random()%10 + 1));

 }


