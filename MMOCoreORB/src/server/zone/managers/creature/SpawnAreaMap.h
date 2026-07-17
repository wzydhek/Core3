/*
 * SpawnAreaMap.h
 *
 *  Created on: Nov 2, 2010
 *      Author: da
 */

#pragma once

#include "server/zone/objects/region/SpawnArea.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class SpawnAreaMap : public SynchronizedVectorMap<uint32, ManagedReference<SpawnArea*> > , public Logger {
protected:

	ManagedReference<Zone*> zone;

	SynchronizedVector<ManagedReference<SpawnArea*> > noSpawnAreas;

public:
	SpawnAreaMap();

	SpawnAreaMap(const SpawnAreaMap& l);

	SpawnAreaMap& operator=(const SpawnAreaMap& m);

	virtual ~SpawnAreaMap();

	void unloadMap();

	void addSpawnArea(uint32 spawnHash, ManagedReference<SpawnArea*> area);

	void addNoSpawnArea(ManagedReference<SpawnArea*> area);
};

} // namespace creature
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::creature;
