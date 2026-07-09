/*
 * ColorWithKitSuiCallback.h
 *
 *  Created on: 1/20/215
 *      Author: Nick Rafalski
 *		Credits: TA & Valk
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/ai/DroidObject.h"
#include "server/zone/objects/creature/VehicleObject.h"

class ColorWithKitSuiCallback : public SuiCallback {
	TangibleObject* customizationKit;

public:
	ColorWithKitSuiCallback(ZoneServer* serv, TangibleObject* kitTano);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
