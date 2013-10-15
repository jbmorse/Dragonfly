/*
 * EvilCharacter.cpp
 *
 *  Created on: Sep 25, 2013
 *      Author: Josh
 */

#include "EventOut.h"
#include "EventStep.h"
#include "LogManager.h"
#include "EvilCharacter.h"
#include "stdlib.h"
#include <math.h>
#include "WorldManager.h"
#include "GameManager.h"
#include "GraphicsManager.h"
#include "EventStep.h"
#include "EventRefresh.h"
#include "LevelChange.h"

EvilCharacter::EvilCharacter(int charnumber, bool outDeath) {

	//Dragonfly managers needed for this method
	LogManager &log_manager = LogManager::getInstance();

	//Set object type
	setType("EvilCharacter");

	setAltitude(1);

	//Register for step and refresh
	registerInterest(REFRESH_EVENT);
	registerInterest(STEP_EVENT);

	charnum = charnumber;
	outIsDeath = outDeath;
	drawchar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	tracksPlayer = false;
	trackingTimeout = 0;

	if (charnumber != 0) {
		moveToStart();
	}

}

EvilCharacter::~EvilCharacter() {

}

int EvilCharacter::eventHandler(Event *p_e) {

	if(p_e->getType() == STEP_EVENT) {
		move();
		return 1;
	}

	if (p_e->getType() == OUT_EVENT) {
		out();
		return 1;
	}

	if (p_e->getType() == COLLISION_EVENT) {
		LogManager &logmanager = LogManager::getInstance();
		logmanager.writeLog("EvilCharacter::eventHandler: received Collision event!\n");
		EventCollision *p_collision_event = static_cast <EventCollision *> (p_e);
		hit(p_collision_event);
		return 1;
	}

	if (p_e->getType() == REFRESH_EVENT) {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.markForDelete(this);
	}

    return 0;

}

void EvilCharacter::out() {

	WorldManager &worldmanager = WorldManager::getInstance();
	if (outIsDeath) {
		worldmanager.markForDelete(this);
	}
	else {
		if (getPosition().getX() < 0) {
			//Bounced off left edge
			Position p(0, getPosition().getY());
			setPosition(p);
			setXVelocity(-1 * getXVelocity());
		}
		if (getPosition().getX() > worldmanager.getBoundary().getHorizontal() - 1) {
			//Bounced off right edge
			Position p(worldmanager.getBoundary().getHorizontal() - 1, getPosition().getY());
			setPosition(p);
			setXVelocity(-1 * getXVelocity());
		}
		if (getPosition().getY() < 0) {
			//Bounced off top edge
			Position p(getPosition().getX(), 0);
			setPosition(p);
			setYVelocity(-1 * getYVelocity());
		}
		if (getPosition().getY() > worldmanager.getBoundary().getVertical() - 1) {
			//Bounced off bottom edge
			Position p(getPosition().getX(), worldmanager.getBoundary().getVertical() - 1);
			setPosition(p);
			setYVelocity(-1 * getYVelocity());
		}
	}

}

void EvilCharacter::moveToStart() {

	WorldManager &worldmanager = WorldManager::getInstance();
	Position new_pos;

	int world_horiz = worldmanager.getBoundary().getHorizontal();
	int world_vert = worldmanager.getBoundary().getVertical();

	//x is off the right side of screen
	new_pos.setX(random()%world_horiz);

	//y is in the vertical range
	new_pos.setY(random()%(world_vert-4) + 4);

	//If collision, move right slightly until empty space
	ObjectList collision_list = worldmanager.isCollision(this, new_pos);
	while (!collision_list.isEmpty()) {
		new_pos.setX(new_pos.getX()+1);
		collision_list = worldmanager.isCollision(this, new_pos);
	}

	//Move the character
	worldmanager.moveObject(this, new_pos);

}

void EvilCharacter::hit(EventCollision *p_c) {

	//If Character on Character, ignore
	if ((p_c -> getObject1() -> getType() == "Character") &&
			(p_c -> getObject2() -> getType() == "Character")) {
		return;
	}

	WorldManager &world_manager = WorldManager::getInstance();
	world_manager.markForDelete(this);

}

void EvilCharacter::draw() {

	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawCh(this->getPosition(), drawchar[charnum], COLOR_RED);

}

char EvilCharacter::getChar() {

	return drawchar[charnum];

}

void EvilCharacter::move() {
	if(tracksPlayer) {
		trackingTimeout--;
		// Check if it's time to change direction
		if(trackingTimeout <= 0) {
			// Move character towards the player
			// Get this character's potiions and the player's position
			Position charPos = getPosition();
			Position playerPos = Position(-1000, -1000);

			ObjectList ol = WorldManager::getInstance().getAllObjects();
			ObjectListIterator li = ol.createIterator();
			for(li.first(); !li.isDone(); li.next()) {
				if(li.currentObject()->getType() == "Hero") {
					playerPos = li.currentObject()->getPosition();
				}
			}

			if(playerPos.getX() == -1000 &&
			   playerPos.getY() == -1000) // player isn't around for some reason
				return;

			float x_velocity;
			float y_velocity;

			// Get x and y distances between two objects
			int x_distance = playerPos.getX() - charPos.getX();
			int y_distance = playerPos.getY() - charPos.getY();

			// Convert them so that the magnitude of the velocity
			// vector is sqrt(1)
			float magnitude = pow((pow(x_distance, 2) + pow(y_distance, 2)), 0.5);
			x_velocity = ((float)x_distance) / magnitude;
			y_velocity = ((float)y_distance) / magnitude;

			// Set velocity, slowing it down a little more
			setXVelocity(x_velocity * 0.85);
			setYVelocity(y_velocity * 0.85);

			// Reset timeout
			trackingTimeout = GameManager::getInstance().getFrameTime() * 1.5;
		}
	}
}

void EvilCharacter::setTracksPlayer(bool newTracksPlayer) {
	tracksPlayer = newTracksPlayer;
}
