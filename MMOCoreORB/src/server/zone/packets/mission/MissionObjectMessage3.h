/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/mission/MissionObject.h"

/*
 * Unforunately, the way SOE designed the baseline/delta system with missions makes it
 * impossible to set variables in the baseline past #4.
 * Variables past #4 must be set to 0, and filled in later with the delta.
 * Talk to Ramsey for more details.
 */

class MissionObjectMessage3 : public BaseLineMessage {

public:

	MissionObjectMessage3(MissionObject* mi);

};
