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

/*
 * The TargetString object is used for displaying purposes of what
 * the player should be collecting for the level.
 * This appears in the top right corner.
 */
class TargetString : public ViewObject {

public:
	TargetString(string complete_string);
	void draw();
};

#endif // _TARGETSTRING_H_
