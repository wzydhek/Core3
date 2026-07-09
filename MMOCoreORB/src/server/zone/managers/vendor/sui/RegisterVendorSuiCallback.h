/*
 * RegisterVendorSuiCallback.h
 *
 *  Created on: May 1, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/vendor/VendorManager.h"

class RegisterVendorSuiCallback : public SuiCallback {
public:
	RegisterVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
