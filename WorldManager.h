/*
 * WorldManager.h
 *
 *  Created on: Sep 17, 2013
 *      Author: Josh
 */

#ifndef WORLDMANAGER_H_
#define WORLDMANAGER_H_

//Game engine header files
#include "Manager.h"
#include "ObjectList.h"
#include "Box.h"

//Misc required headers

#define MAX_ALTITUDE 4

class WorldManager : public Manager {

private:
	WorldManager();					 		//Singleton
	WorldManager(WorldManager const&); 		//Disallow copying
	void operator=(WorldManager const&);	//Disallow assignment
	ObjectList updates;			//List of all Objects in the world to update
	ObjectList deletions;		//List of all Objects in the world to delete
	Box boundary;				//World boundary
	Box view;					//Player view of game world
	Object *p_view_following;	//Object view is following

public:
	static WorldManager &getInstance();	//Get the singleton
	int startUp();						//Initialize world to empty
	void shutDown();					//Delete all world Objects
	int insertObject(Object *p_o);		//Add Object to world (0 if okay, -1 if error)
	int removeObject(Object *p_o);		//Remove Object to world (0 if okay, -1 if error)
	ObjectList getAllObjects();			//Return list of all Objects in world
	void update();						//Update world and delete objects in deletions
	int markForDelete(Object *p_o);		//Indicate object should be deleted (0 if okay, -1 if error)
	bool isValid(string event_name);	//Accepts world manager events
	void draw(); 						//Draw all objects
	ObjectList isCollision(Object *p_o, Position where); //Return list of Objects collided at where
	int moveObject(Object *p_o, Position where);	//Move object to position
	Box getBoundary();					//Get game world boundary
	void setBoundary(Box new_boundary);	//Set game world boundary
	Box getView();						//Get player view of world
	void setView(Box new_view);			//Set player view of world
	void setViewPosition(Position view_pos);	//Set view center on pos
	int setViewFollowing(Object *p_newvf);		//Set view center on object

};

#endif /* WORLDMANAGER_H_ */
