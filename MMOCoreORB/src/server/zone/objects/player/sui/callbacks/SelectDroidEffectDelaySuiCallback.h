/*
 * SelectDroidEffectDelaySuiCallback.h
 *
 *  Created on: November 30, 2014
 *      Author: Klivian
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/tangible/components/droid/DroidEffectsModuleDataComponent.h"

class SelectDroidEffectDelaySuiCallback : public SuiCallback, public Logger {

	Reference<DroidEffectsModuleDataComponent*> module;
	String effectName;
	int slotIndex;

public:
	SelectDroidEffectDelaySuiCallback(ZoneServer* serv, DroidEffectsModuleDataComponent* module, String effectName, int slotIndex);

	void run(CreatureObject* player, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
