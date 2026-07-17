/*
 * LairObjectsToSpawnMap.h
 *
 *  Created on: 15/07/2010
 *      Author: victor
 */

#pragma once

#include "system/util/VectorMap.h"

namespace server {
namespace zone {
namespace managers {
namespace mission {

class LairObjectsToSpawnMap : public VectorMap<int, Vector<uint32> > {
public:
	const static int MAXPLANETS = 10;

	LairObjectsToSpawnMap();

	void addTemplate(int planetID, uint32 templateCRC);

	void insertTemplateToAllPlanets(uint32 templateCRC);

	uint32 getRandomTemplate(int planetID) const;
};

} // namespace mission
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::mission;
