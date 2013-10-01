/*
 * Object.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef OBJECT_H_
#define OBJECT_H_

//Game engine header files
#include "Position.h"
#include "Event.h"
#include "Sprite.h"

//Misc required headers
#include "string"

using std::string;

enum Solidness {
	HARD,     //Objects cause collisions and impede.
	SOFT,     //Objects cause collisions, but don't impede.
	SPECTRAL  //Objects don't cause collisions.
};


#define MAX_OBJ_EVENTS 30

class Object {

private:
	string type;						//User defined identification
	Position pos;						//Position in world
	int event_count;					//Interested event count
	string event_name[MAX_OBJ_EVENTS];	//List of interested events
	int altitude;						//0 to MAX supported
	float x_velocity;           		//Horizontal speed in spaces per step
	float x_velocity_countdown; 		//Countdown to horizontal movement
	float y_velocity;           		//Vertical speed in spaces per step
	float y_velocity_countdown; 		//Countdown to vertical movement
	Solidness solidness;				//Collision solidness
	Sprite *p_sprite;					//Sprite associated with the object
	bool sprite_centered;				//True if sprite is centered on object
	int sprite_index;					//Current index frame for sprite
	int sprite_slowdown;				//Slowdown rate (1 = no slowdown, 0 = stop)
	int sprite_slowdown_count;			//Slowdown counter

public:
	Object();
	virtual ~Object();
	void setType(string new_type); 				//Set type identifier of object
	string getType();							//Get type identifier of object
	void setPosition(Position new_pos);			//Set position of object
	Position getPosition();						//Get position of object
	virtual int eventHandler(Event *p_e);		//(0 if ignored, 1 otherwise)
	int registerInterest(string event_type);	//Add interest in event
	int unregisterInterest(string event_type);	//Remove interest in event
	virtual void draw();						//Draw single sprite frame
	int setAltitude(int new_altitude);			//Set object altitude
	int getAltitude();							//Return object altitude
	void setXVelocity(float new_x_velocity);	//Set X Velocity
	float getXVelocity();						//Get X Velocity
	void setYVelocity(float new_y_velocity);	//Set Y Velocity
	float getYVelocity();						//Get Y Velocity
	int getXVelocityStep();						//Step in the X direction
	int getYVelocityStep();						//Step in the Y direction
	bool isSolid();								//Returns true if HARD or SOFT
	int setSolidness(Solidness new_solid);		//Set solidness
	Solidness getSolidness();					//Get solidness
	void setSprite(Sprite *p_new_sprite);		//Set sprite to be associated with object
	void setSprite(Sprite *p_new_sprite, bool set_box);	//Set box to size of sprite if true
	Sprite *getSprite();						//Get sprite
	void setCentered(bool centered);			//Set centered
	bool isCentered();							//Get centered
	void setSpriteIndex(int new_sprite_index);	//Set index of sprite frame
	int getSpriteIndex();						//Get index of sprite frame
	void setSpriteSlowdown(int new_slowdown);	//Set slowdown of animation
	int getSpriteSlowdown();					//Get slowdown of animation
	void setSpriteSlowdownCount(int new_sd_count);	//Set slowdown count
	int getSpriteSlowdownCount();					//Get slowdown count

};

#endif /* OBJECT_H_ */
