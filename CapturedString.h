/*
 * CapturedString.h
 *
 *   Created: Oct. 8, 2013
 *     Author: Tim
 */

#ifndef _CAPTUREDSTRING_H_
#define _CAPTUREDSTRING_H_

// System includes
#include <string>
// Engine includes
#include "Event.h"
#include "ViewObject.h"
// Using statements
using std::string;

class CapturedString : public ViewObject {

private:
	void addLetter(char letter);
	string complete_string;

public:
	CapturedString();
	CapturedString(string new_complete_string);
	int eventHandler(Event *p_e);
	void draw();
	string getCompleteString();
	void setCompleteString(string new_complete_string);
};

#endif // _CAPTUREDSTRING_H_
