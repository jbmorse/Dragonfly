/*
 * EventCapturedLetter.cpp
 *
 *   Created: Oct 8, 2013
 *     Author: Tim
 */

// Class include
#include "EventCapturedLetter.h"

EventCapturedLetter::EventCapturedLetter() {
	setType(CAPTURED_LETTER_EVENT);
	captured_letter = ' ';
}

void EventCapturedLetter::setCapturedLetter(char c) {
	captured_letter = c;
}

char EventCapturedLetter::getCapturedLetter() {
	return captured_letter;
}
