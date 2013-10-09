/*
 * CapturedString.h
 *
 *   Created: Oct. 8, 2013
 *     Author: Tim
 */

#ifndef _CAPTUREDSTRING_H_
#define _CAPTUREDSTRING_H_

// Engine includes
#include "Event.h"
#include "ViewObject.h"

class CapturedString : public ViewObject {

private:
	void addLetter(char letter);

public:
	CapturedString();
	int eventHandler(Event *p_e);
	void draw();
};

#endif // _CAPTUREDSTRING_H_
