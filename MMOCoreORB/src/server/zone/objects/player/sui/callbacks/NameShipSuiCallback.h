/*
 * NameShipSuiCallback.h
 *
 *  Created on: 1/26/2024
 *  Author: Hakry
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/ZoneProcessServer.h"
#include "server/zone/managers/name/NameManager.h"
#include "templates/tangible/ship/SharedShipObjectTemplate.h"

class NameShipSuiCallback : public SuiCallback {
public:
	NameShipSuiCallback(ZoneServer* serv);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
