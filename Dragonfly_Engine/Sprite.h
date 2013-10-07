/*
 * Sprite.h
 *
 *  Created on: Sep 28, 2013
 *      Author: Josh
 */

#ifndef SPRITE_H_
#define SPRITE_H_

//Game engine header files
#include "Frame.h"

//Misc required headers
#include <string>

using std::string;

class Sprite {

private:
	int width;					//Sprite width
	int height;					//Sprite height
	int max_frame_count;		//Maximum number of frames
	int frame_count;			//Actual frame
	int color;					//Optional color
	Frame *frame;				//Array of frames
	string label;				//Text label
	Sprite();					//Illegal Sprite constructor

public:
	Sprite(int max_frames);			//Create sprite with indicated maximum number of frames
	~Sprite();						//Destroy Sprite, deleting any allocated frames
	int getWidth(); 				//Get width of Sprite
	void setWidth(int new_width);	//Set width of Sprite
	int getHeight();				//Get height of Sprite
	void setHeight(int new_height);	//Set height of sprite
	int getColor();					//Get sprite color
	void setColor(int new_color); 	//Set sprite color
	int getFrameCount();			//Get total count of frames in sprite
	Frame getFrame(int frame_number);//Get next sprite frame indicated by number (or empty frame if out of range)
	int addFrame(Frame new_frame);	//Add frame to sprite
	string getLabel(); 				//Get label associated with sprite
	void setLabel(string new_label);//Set label associated with sprite

};

#endif /* SPRITE_H_ */
