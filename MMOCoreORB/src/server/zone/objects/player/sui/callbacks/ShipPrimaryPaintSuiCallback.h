/*
 * ShipPrimaryPaintSuiCallback.h
 *
 *  Created on: 7/16/2023
 *      Author: Halyn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"
#include "server/zone/objects/player/sui/callbacks/ShipColorWithKitSuiCallback.h"
#include "server/zone/objects/tangible/tool/ShipPaintKit.h"

class ShipPrimaryPaintSuiCallback : public SuiCallback {
	ManagedWeakReference<ShipPaintKit*> customizationKit;
public:
	ShipPrimaryPaintSuiCallback(ZoneServer* serv, ShipPaintKit* kit);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
