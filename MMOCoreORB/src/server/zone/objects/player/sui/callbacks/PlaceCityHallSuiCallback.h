/*
 * PlaceCityHallSuiCallback.h
 *
 *  Created on: Feb 5, 2012
 *      Author: xyborn
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/tangible/deed/structure/StructureDeed.h"
#include "server/zone/managers/structure/StructureManager.h"
#include "server/zone/managers/planet/PlanetManager.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/Zone.h"
#include "server/zone/ZoneProcessServer.h"

class PlaceCityHallSuiCallback : public SuiCallback, public Logger {
	ManagedWeakReference<Zone*> zone;
	ManagedWeakReference<StructureDeed*> deed;

	float x;
	float y;
	int angle;

public:
	PlaceCityHallSuiCallback(Zone* zone, StructureDeed* deed, float x, float y, int angle);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
