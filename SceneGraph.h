/*
 * SceneGraph.h
 *
 *  Created on: Oct 4, 2013
 *      Author: Josh
 */

#ifndef SCENEGRAPH_H_
#define SCENEGRAPH_H_

//Game engine header files
#include "Object.h"
#include "ObjectList.h"

//Misc required headers

#define MAX_ALTITUDE 4
#define MAX_LEVEL 100		//Level 0 objects are persistent

class SceneGraph {

private:
	int level;										//Level the game is on
	ObjectList objects[MAX_LEVEL+1];								//All objects
	ObjectList solid_objects[MAX_LEVEL+1];						//Solid objects
	ObjectList visible_objects[MAX_LEVEL+1][MAX_ALTITUDE+1];		//Visible objects

public:
	SceneGraph();
	~SceneGraph();
	int insertObject(Object *p_o);			//Insert Object into SceneGraph
	int removeObject(Object *p_o);			//Remove Object from SceneGraph
	ObjectList allObjects();				//Return all Objects
	ObjectList solidObjects();				//Return all solid Objects
	ObjectList visibleObjects(int altitude);//Return all visible Objects at altitude
	int updateAltitude(Object *p_o, int new_alt);				//Re-position Object to new altitude
	int updateSolidness(Object *p_o, Solidness new_solidness);	//Re-position Object to new solidness
	int setLevel(int new_level);			//Set game level
	int getLevel();							//Get game level
	int updatePersistence(Object *p_o, bool new_persistence);	//Re-position Object to new persistence

};

#endif /* SCENEGRAPH_H_ */
