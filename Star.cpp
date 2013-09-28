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
	GraphicsManager &graphics_manager = GraphicsManager::getInstance();
	Position pos(random()%graphics_manager.getHorizontal(), random()%graphics_manager.getVertical());
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

	GraphicsManager &graphics_manager = GraphicsManager::getInstance();
	Position pos(graphics_manager.getHorizontal() + random()%20, random() % graphics_manager.getVertical());
	setPosition(pos);
	setXVelocity(-1.0 / (random()%10 + 1));

 }


