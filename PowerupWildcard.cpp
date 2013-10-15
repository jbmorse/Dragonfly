/*
 * PowerupWildcard.cpp
 *
 *   Created: Oct 10, 2013
 *    Author: Tim
 */

// Class include
#include "PowerupWildcard.h"
// System includes
#include <stdlib.h>
// Engine includes
#include "EventCollision.h"
#include "EventOut.h"
#include "GraphicsManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Utility.h"
#include "WorldManager.h"

PowerupWildcard::PowerupWildcard() {
	LogManager &lm = LogManager::getInstance();
	ResourceManager &rm = ResourceManager::getInstance();

	setType("PowerupWildcard");

	setXVelocity(-0.25);

	setSolidness(SOFT);

	setAltitude(0);

	registerInterest(OUT_EVENT);

	WorldManager &wm = WorldManager::getInstance();
	int view_horiz = wm.getView().getHorizontal();
	int view_vert = wm.getView().getHorizontal();
	Position temp_pos(view_horiz + 10,
		random() % (view_vert - 4) + 4);
	temp_pos = viewToWorld(temp_pos);
	setPosition(temp_pos);
}

int PowerupWildcard::eventHandler(Event *p_e) {
	if(p_e->getType() == OUT_EVENT) {
		WorldManager::getInstance().markForDelete(this);
	} else if(p_e->getType() == COLLISION_EVENT) {
		EventCollision *p_c = (EventCollision *)p_e;

		// Only delete if colliding with hero or boss
		if(p_c->getObject1()->getType() == "Hero" ||
		   p_c->getObject2()->getType() == "Hero" || 
		   p_c->getObject1()->getType() == "BossSkull" ||
		   p_c->getObject2()->getType() == "BossSkull")
			WorldManager::getInstance().markForDelete(this);
	}
}

void PowerupWildcard::draw() {
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawCh(this->getPosition(), '*', COLOR_GREEN);
}
