/*
 * EventCapturedLetter.h
 *
 *   Created: Oct 8, 2013
 *     Author: Tim
 */

#ifndef _EVENTCAPTUREDLETTER_H_
#define _EVENTCAPTUREDLETTER_H_

// Engine includes
#include "Event.h"

#define CAPTURED_LETTER_EVENT "_capturedletter_"

class EventCapturedLetter : public Event {

private:
	char captured_letter;

public:
	EventCapturedLetter();
	char getCapturedLetter();
	void setCapturedLetter(char c);

};

#endif // _EVENTCAPTUREDLETTER_H_
