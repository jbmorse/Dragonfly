/*
 * Frame.cpp
 *
 *  Created on: Sep 28, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Frame.h"

//Misc required headers

Frame::Frame() {

	width = 0;
	height = 0;
	frame_str = "";

}

Frame::Frame(int new_width, int new_height, string new_frame_str) {

	width = new_width;
	height = new_height;
	frame_str = new_frame_str;

}

int Frame::getWidth() {

	return width;

}

void Frame::setWidth(int new_width) {

	width = new_width;

}

int Frame::getHeight() {

	return height;

}

void Frame::setHeight(int new_height) {

	height = new_height;

}

string Frame::getString() {

	return frame_str;

}

void Frame::setFrame(string new_frame_str) {

	frame_str = new_frame_str;

}
