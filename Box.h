/*
 * Box.h
 *
 *  Created on: Oct 1, 2013
 *      Author: Josh
 */

#ifndef BOX_H_
#define BOX_H_

//Game engine header files
#include "Position.h"

//Misc required headers

class Box {

private:
	Position corner;   //Top left corner of box
	int horizontal;    //Horizontal width
	int vertical;      //Vertical height

public:

	Box();										//Create blank box
	Box(Position init_corner, int init_horizontal, int init_vertical);	//Create custom box
	Position getCorner();						//Get top left corner of box
	void setCorner(Position new_corner);		//Set top left corner of box
	int getHorizontal();						//Get horizontal size
	void setHorizontal(int new_horizontal);		//Set horizontal size
	int getVertical();							//Get vertical size
	void setVertical(int new_vertical);			//Set vertical size

};



#endif /* BOX_H_ */
