/*
 * SpawnAreaMap.cpp
 *
 *  Created on: 12/08/2011
 *      Author: TheAnswer
 */

#include "SpawnAreaMap.h"
#include "server/zone/Zone.h"
#include "server/zone/managers/object/ObjectManager.h"
#include "templates/params/creature/ObjectFlag.h"
#include "server/zone/objects/area/areashapes/CircularAreaShape.h"
#include "server/zone/objects/area/areashapes/RectangularAreaShape.h"
#include "server/zone/objects/area/areashapes/RingAreaShape.h"

SpawnAreaMap::SpawnAreaMap() : Logger("SpawnAreaMap") {
	setAllowDuplicateInsertPlan();
}

SpawnAreaMap::SpawnAreaMap(const SpawnAreaMap& l) : SynchronizedVectorMap<uint32, ManagedReference<SpawnArea*>>(l), Logger("SpawnAreaMap"), zone(l.zone), noSpawnAreas(l.noSpawnAreas) {
}

SpawnAreaMap& SpawnAreaMap::operator=(const SpawnAreaMap& m) {
	if (this == &m) {
		return *this;
	}

	zone = m.zone;
	noSpawnAreas = m.noSpawnAreas;

	return *this;
}

SpawnAreaMap::~SpawnAreaMap() {
}

void SpawnAreaMap::unloadMap() {
	noSpawnAreas.removeAll();

	for (int i = 0; i < size(); i++) {
		SpawnArea* area = get(i);

		if (area != nullptr) {
			Locker locker(area);
			area->destroyObjectFromWorld(false);
		}
	}

	removeAll();
}

void SpawnAreaMap::addSpawnArea(uint32 spawnHash, ManagedReference<SpawnArea*> area) {
	put(spawnHash, area);
}

void SpawnAreaMap::addNoSpawnArea(ManagedReference<SpawnArea*> area) {
	noSpawnAreas.add(area);
}