/*
 * Object.cpp
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Object.h"
#include "Position.h"
#include "WorldManager.h"
#include "LogManager.h"
#include "EventStep.h"
#include "GameManager.h"
#include "EventMouse.h"
#include "EventKeyboard.h"
#include "InputManager.h"
#include "GraphicsManager.h"
#include "Utility.h"

//Misc required headers
#include "math.h"

Object::Object() {

	altitude = 0;
	event_count = 0;
	x_velocity = 0;
	x_velocity_countdown = 0;
	y_velocity = 0;
	y_velocity_countdown = 0;
	solidness = HARD;
	p_sprite = NULL;
	sprite_centered = true;
	sprite_index = 0;
	sprite_slowdown = 1;
	sprite_slowdown_count = 0;
	type = "Object";
	box = Box();
	pos = Position();
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.insertObject(this);
	is_persistent = false;

}

Object::~Object() {

	for (int i = event_count; i > 0; i--) {
		unregisterInterest(event_name[i-1]);
	}
	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.removeObject(this);

}

void Object::setType(string new_type) {

	type = new_type;

}

string Object::getType() {

	return type;

}

void Object::setPosition(Position new_pos) {

	pos = new_pos;

}

Position Object::getPosition() {

	return pos;

}

int Object::eventHandler(Event *p_e) {

	LogManager &logmanager = LogManager::getInstance();
	logmanager.writeLog("Object::eventHandler: Object received event!\n");

	//For now all objects will move to the right when they receive an event (to be removed)
	if (p_e->getType() == STEP_EVENT) {
		this->setPosition(Position(pos.getX() + 1,pos.getY()));
		logmanager.writeLog("Object::eventHandler: Object set position (%d, %d)!\n", pos.getX(), pos.getY());
	}
	return 1;

}

int Object::registerInterest(string event_type) {

	if (event_count == MAX_OBJ_EVENTS) {
		return -1;
	}

	if (event_type == STEP_EVENT) {
		GameManager &gamemanager = GameManager::getInstance();
		gamemanager.registerInterest(this, event_type);
	}
	else if (event_type == MOUSE_EVENT || event_type == KEYBOARD_EVENT) {
		InputManager &inputmanager = InputManager::getInstance();
		inputmanager.registerInterest(this, event_type);
	}
	else {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.registerInterest(this, event_type);
	}

	event_name[event_count] = event_type;
	event_count++;

	return 0;

}

int Object::unregisterInterest(string event_type) {

	if (event_type == STEP_EVENT) {
		GameManager &gamemanager = GameManager::getInstance();
		gamemanager.unregisterInterest(this, event_type);
	}
	else if (event_type == MOUSE_EVENT || event_type == KEYBOARD_EVENT) {
		InputManager &inputmanager = InputManager::getInstance();
		inputmanager.unregisterInterest(this, event_type);
	}
	else {
		WorldManager &worldmanager = WorldManager::getInstance();
		worldmanager.unregisterInterest(this, event_type);
	}

	for (int i = 0; i < event_count; i++) {
		if (event_name[i] == event_type) {
			for (; i < event_count-1; i++) {
				event_name[i] = event_name[i+1];
			}
		}
	}

	event_count--;

	return 0;

}

void Object::draw() {

	if (p_sprite == NULL) return;	//No sprite to draw

	//Draw current frame
	GraphicsManager &graphicsmanager = GraphicsManager::getInstance();
	graphicsmanager.drawFrame(pos, p_sprite->getFrame(sprite_index), sprite_centered, p_sprite->getColor());

	if (sprite_slowdown == 0) return;	//Frozen sprite

	int count = sprite_slowdown_count + 1;
	if (count >= sprite_slowdown) {
		count = 0;
		sprite_index++;

		if (sprite_index >= p_sprite->getFrameCount()) {
			sprite_index = 0;	//Loop frames to beginning
		}

	}

	  setSpriteSlowdownCount(count);

}

int Object::setAltitude(int new_altitude) {

	if (!valueInRange(new_altitude, 0, MAX_ALTITUDE)) {
		return -1;
	}

	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.getSceneGraph().updateAltitude(this, new_altitude);
	altitude = new_altitude;

	return 0;

}

int Object::getAltitude() {

	return altitude;

}

void Object::setXVelocity(float new_x_velocity) {

	x_velocity = new_x_velocity;

}

float Object::getXVelocity(){

	return x_velocity;

}

void Object::setYVelocity(float new_y_velocity) {

	y_velocity = new_y_velocity;
}

float Object::getYVelocity() {

	return y_velocity;

}

int Object::getXVelocityStep() {

	if (x_velocity == 0) return 0; //No velocity

	x_velocity_countdown -= fabs(x_velocity);
	if (x_velocity_countdown > 0) return 0; //Not time to move

	int spaces = floor(1 - x_velocity_countdown);
	x_velocity_countdown = 1 + fmod(x_velocity_countdown, 1);

	if (x_velocity > 0) return spaces; //Positive velocity
	else return (-1 * spaces);	//Negative velocity

}

int Object::getYVelocityStep() {

	if (y_velocity == 0) return 0; //No velocity

	y_velocity_countdown -= fabs(y_velocity);
	if (y_velocity_countdown > 0) return 0; //Not time to move

	int spaces = floor(1 - y_velocity_countdown);
	y_velocity_countdown = 1 + fmod(y_velocity_countdown, 1);

	if (y_velocity > 0) return spaces; //Positive velocity
	else return (-1 * spaces);	//Negative velocity

}

bool Object::isSolid() {

	return (solidness == HARD || solidness == SOFT);

}

int Object::setSolidness(Solidness new_solid) {

	if (new_solid == this->getSolidness()) {
		return -1;
	}

	WorldManager &worldmanager = WorldManager::getInstance();
	worldmanager.getSceneGraph().updateSolidness(this, new_solid);
	solidness = new_solid;
	return 0;

}

Solidness Object::getSolidness() {

	return solidness;

}

void Object::setSprite(Sprite *p_new_sprite) {

	p_sprite = p_new_sprite;
	Position temp_pos;
	if (sprite_centered) {
		int x_offset = p_sprite->getWidth() /-2;
		int y_offset = p_sprite->getHeight() /-2;
		temp_pos = Position(x_offset, y_offset);
	}
	else {
		temp_pos = Position(0,0);
	}

	box = Box(temp_pos, p_sprite->getWidth(), p_sprite->getHeight());

}

void Object::setSprite(Sprite *p_new_sprite, bool set_box) {

	p_sprite = p_new_sprite;
	if (set_box) {
		Position temp_pos;
		if (sprite_centered) {
			int x_offset = p_sprite->getWidth() /-2;
			int y_offset = p_sprite->getHeight() /-2;
			temp_pos = Position(x_offset, y_offset);
		}
		else {
			temp_pos = Position(0,0);
		}

		box = Box(temp_pos, p_sprite->getWidth(), p_sprite->getHeight());
	}
	else {
		box = Box();
	}

}

Sprite *Object::getSprite() {

	return p_sprite;

}

void Object::setCentered(bool centered) {

	if (sprite_centered != centered) {
		if (centered) {
			int x_offset = p_sprite->getWidth() /-2;
			int y_offset = p_sprite->getHeight() /-2;
			box.setCorner(Position(x_offset, y_offset));
		}
		else {
			box.setCorner(Position(0,0));
		}
		sprite_centered = centered;
	}

}

bool Object::isCentered() {

	return sprite_centered;

}

void Object::setSpriteIndex(int new_sprite_index) {

	sprite_index = new_sprite_index;

}

int Object::getSpriteIndex() {

	return sprite_index;

}

void Object::setSpriteSlowdown(int new_slowdown) {

	sprite_slowdown = new_slowdown;

}

int Object::getSpriteSlowdown() {

	return sprite_slowdown;

}

void Object::setSpriteSlowdownCount(int new_sd_count) {

	sprite_slowdown_count = new_sd_count;

}

int Object::getSpriteSlowdownCount() {

	return sprite_slowdown_count;

}

void Object::setBox(Box new_box) {

	box = new_box;

}

Box Object::getBox() {

	return box;

}

int Object::setPersistence(bool persistent)	{

	LogManager &logmanager = LogManager::getInstance();
	WorldManager &worldmanager = WorldManager::getInstance();
	SceneGraph &scene_graph = worldmanager.getSceneGraph();
	if (scene_graph.updatePersistence(this, persistent)) {
		return -1;
	}

	is_persistent = persistent;

	return 0;

}

bool Object::isPersistent() {

	return is_persistent;

}
