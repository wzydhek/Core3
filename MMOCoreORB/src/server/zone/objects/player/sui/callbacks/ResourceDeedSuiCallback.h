/*
 * ResourceDeedSuiCallback.h
 *
 *  Created on: Aug 17, 2011
 *      Author: crush
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ResourceDeedSuiCallback : public SuiCallback {
	String nodeName;

public:
	ResourceDeedSuiCallback(ZoneServer* serv, const String& name);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
