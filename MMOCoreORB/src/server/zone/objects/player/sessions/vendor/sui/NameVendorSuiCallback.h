/*
 * NameVendorSuiCallback.h
 *
 *  Created on: Mar 20, 2011
 *      Author: polonel
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sessions/vendor/CreateVendorSession.h"

class NameVendorSuiCallback : public SuiCallback {
public:
	NameVendorSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
