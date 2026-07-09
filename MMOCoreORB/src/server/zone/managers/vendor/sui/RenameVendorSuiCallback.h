/*
 * RenameVendorSuiCallback.h
 *
 *  Created on: Mar 27, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/vendor/VendorManager.h"

class RenameVendorSuiCallback : public SuiCallback {
public:
	RenameVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
