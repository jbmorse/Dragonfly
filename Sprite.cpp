/*
 * Sprite.cpp
 *
 *  Created on: Sep 28, 2013
 *      Author: Josh
 */

//Game engine header files
#include "Sprite.h"
#include "GraphicsManager.h"

//Misc required headers

Sprite::Sprite(int max_frames) {

	frame_count = 0;
	width = 0;
	height = 0;
	frame = new Frame[max_frames];
	max_frame_count = max_frames;
	color = COLOR_DEFAULT;

}

Sprite::~Sprite() {

	if (frame != NULL) {
		delete []frame;
	}

}

int Sprite::getWidth() {

	return width;

}

void Sprite::setWidth(int new_width) {

	width = new_width;

}

int Sprite::getHeight() {

	return height;

}

void Sprite::setHeight(int new_height) {

	height = new_height;

}

int Sprite::getColor() {

	return color;

}

void Sprite::setColor(int new_color) {

	color = new_color;

}

int Sprite::getFrameCount() {

	return frame_count;

}

Frame Sprite::getFrame(int frame_number) {

	if ((frame_number < 0) || (frame_number >= frame_count)) {
		Frame empty = Frame();
		return empty;
	}

	return frame[frame_number];

}

int Sprite::addFrame(Frame new_frame) {

	if (frame_count == max_frame_count) {
		return -1;
	}
	else {
		frame[frame_count] = new_frame;
		frame_count++;
	}

	return 0;

}

string Sprite::getLabel() {

	return label;

}

void Sprite::setLabel(string new_label) {

	label = new_label;

}
