/*
 * TargetString.h
 *
 *   Created: Oct. 8, 2013
 *     Author: Tim
 */

#ifndef _TARGETSTRING_H_
#define _TARGETSTRING_H_

// System includes
#include <string>
// Engine includes
#include "ViewObject.h"
// Using statements
using std::string;

class TargetString : public ViewObject {

public:
	TargetString(string complete_string);
	void draw();
};

#endif // _TARGETSTRING_H_
