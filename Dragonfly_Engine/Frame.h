/*
 * Frame.h
 *
 *  Created on: Sep 28, 2013
 *      Author: Josh
 */

#ifndef FRAME_H_
#define FRAME_H_

//Game engine header files

//Misc required headers
#include <string>

using std::string;

class Frame {

private:
	int width;			//Width of frame
	int height;			//Height of frame
	string frame_str;	//All frame characters

public:
	Frame();
	Frame(int new_width, int new_height, string new_frame_str);
	int getWidth();						//Get width of frame
	void setWidth(int new_width);		//Set width of frame
	int getHeight();					//Get height of frame
	void setHeight(int new_height);		//Set height of frame
	string getString();					//Get frame characters
	void setFrame(string new_frame_str);//Set frame characters

};



#endif /* FRAME_H_ */
