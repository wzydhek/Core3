/*
 * CustomVehicleSuiCallback.h
 *
 *  Created on: May 5, 2013
 *      Author: Trick77
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/listbox/SuiListBox.h"
#include "server/zone/objects/player/sui/colorbox/SuiColorBox.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/player/sui/callbacks/ColorWithKitSuiCallback.h"

class CustomVehicleSuiCallback : public SuiCallback {
	int numPalette;
	TangibleObject* customizationKit;

public:
	CustomVehicleSuiCallback(ZoneServer* serv, int palette, TangibleObject* kitTano);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
