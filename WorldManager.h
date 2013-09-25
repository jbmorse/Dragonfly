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

//Misc required headers

#define MAX_ALTITUDE 4

class WorldManager : public Manager {

private:
	WorldManager();					 		//Singleton
	WorldManager(WorldManager const&); 		//Disallow copying
	void operator=(WorldManager const&);	//Disallow assignment
	ObjectList updates;			//List of all Objects in the world to update
	ObjectList deletions;		//List of all Objects in the world to delete

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



};

#endif /* WORLDMANAGER_H_ */
