/*
 * ViewObject.h
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

#ifndef VIEWOBJECT_H_
#define VIEWOBJECT_H_

//Game engine header files
#include "Object.h"
#include "Event.h"

//Misc required headers
#include <string>

using std::string;

//General location of ViewObject on screen
enum ViewObjectLocation {
	TOP_LEFT,
	TOP_CENTER,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_CENTER,
	BOTTOM_RIGHT,
};

class ViewObject : public Object {

private:
	string view_string;  //Label for value
	int value;           //Value displayed
	bool border;         //True if border around display
	int color;           //Color for text

public:
	ViewObject();							//ViewObject defaults: border, top_center, default color
	virtual void draw(); 					//Draw view string and value
	virtual int eventHandler(Event *p_e);	//Handle `view' event if tag matches view_string
	void setLocation(ViewObjectLocation new_location);	//General location of ViewObject on screen
	void setValue(int new_value);			//Set view value
	int getValue();							//Get view value
	void setBorder(bool new_border);		//Set view border
	bool getBorder();						//Get view border
	void setColor(int new_color);			//Set view color
	int getColor();							//Get view color
	void setViewString(string new_view_string);		//Set view display string
	string getViewString(); 						//Get view display string

};


#endif /* VIEWOBJECT_H_ */
