/*
 * RenameCitySuiCallback.h
 *
 *  Created on: Sep 2, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/region/CityRegion.h"
#include "server/zone/managers/city/CityManager.h"
#include "server/zone/managers/name/NameManager.h"
#include "server/zone/managers/planet/PlanetManager.h"

class RenameCitySuiCallback : public SuiCallback {
	ManagedWeakReference<Zone*> zne;
	ManagedWeakReference<CityRegion*> city;

public:
	RenameCitySuiCallback(Zone* zone, CityRegion* city);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
