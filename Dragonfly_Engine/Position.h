/*
 * Position.h
 *
 *  Created on: Sep 15, 2013
 *      Author: Josh
 */

#ifndef POSITION_H_
#define POSITION_H_

//Game engine header files
//Misc required headers

class Position {

private:
	int x; //Horizontal coordinate
	int y; //Vertical coordinate

public:
	Position(int init_x, int init_y); 	//Create object at given 2d location (x,y)
	Position(); 						//Create object at default 2d location (0,0)
	int getX();
	void setX(int new_x);
	int getY();
	void setY(int new_y);
	void setXY(int new_x, int new_y);

};


#endif /* POSITION_H_ */
