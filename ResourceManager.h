/*
 * ResourceManager.h
 *
 *  Created on: Sep 28, 2013
 *      Author: Josh
 */

#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

//Game engine header files
#include "Manager.h"
#include "Sprite.h"

//Misc required headers
#include <string>

#define MAX_SPRITES 10000

//Delimiters used to parse Sprite files - the ResourceManager `knows' file format
#define FRAMES_TOKEN "frames"
#define HEIGHT_TOKEN "height"
#define WIDTH_TOKEN "width"
#define COLOR_TOKEN "color"
#define END_FRAME_TOKEN "end"
#define END_SPRITE_TOKEN "eof"

using std::string;

class ResourceManager : public Manager {

private:
	ResourceManager();							//Private (singleton)
	ResourceManager (ResourceManager const&);	//No copying
	void operator=(ResourceManager const&);		//No assignment
	Sprite *p_sprite[MAX_SPRITES];  			//Array of (pointers to) sprites
	int sprite_count;							//Count of number of loaded sprites

public:
	~ResourceManager();
	static ResourceManager &getInstance();			//Get the singleton
	int startUp();									//Ready manager for service
	void shutDown();								//Free up any allocated Sprites
	int loadSprite(string filename, string label);	//Load Sprite from file
	int unloadSprite(string label);					//Unload Sprite with indicated label
	Sprite *getSprite(string label);				//Find Sprite with indicated label

};

#endif /* RESOURCEMANAGER_H_ */
