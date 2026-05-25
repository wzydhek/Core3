/*
 * DelegateSuiCallback.h
 *
 *  Created on: 19/01/2012
 *      Author: victor
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class DelegateSuiCallback : public SuiCallback {
public:
	DelegateSuiCallback(ZoneServer* serv);

	void run(server::zone::objects::creature::CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
