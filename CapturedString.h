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

/*
 * This is the class that handles completing strings.
 * When the hero picks a character up, it will send an
 * EventCapturedLetter, which this class registers.
 * If the character picked up matches one needed, it will
 * add it to the string. Once the complete string is captured,
 * the LevelChange for the next level is created, and the hero
 * is made spectral. The string is shown in the top middle of the screen.
 */
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
