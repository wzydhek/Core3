/*
 * VendorMaintSuiCallback.h
 *
 *  Created on: Feb 5, 2012
 *      Author: Kyle
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/vendor/VendorDataComponent.h"

class VendorMaintSuiCallback : public SuiCallback {

public:
	VendorMaintSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
