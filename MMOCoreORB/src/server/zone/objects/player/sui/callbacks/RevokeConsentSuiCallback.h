/*
 * RevokeConsentSuiCallback.h
 *
 *  Created on: may 5, 2013
 *      Author: trick77
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class RevokeConsentSuiCallback : public SuiCallback {
public:
	RevokeConsentSuiCallback(ZoneServer* server);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
