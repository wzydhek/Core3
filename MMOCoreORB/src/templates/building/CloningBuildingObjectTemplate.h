/*
 * CloningBuildingObject.h
 *
 *  Created on: 23/06/2010
 *      Author: victor
 */

#pragma once

#include "templates/building/SharedBuildingObjectTemplate.h"
#include "templates/building/CloneSpawnPoint.h"

namespace templates {
namespace building {

class CloningBuildingObjectTemplate : public SharedBuildingObjectTemplate {
	Vector<CloneSpawnPoint> spawningPoints;
	int facilityType;

public:
	enum { STANDARD = 0, PLAYER_CITY, JEDI_ONLY, LIGHT_JEDI_ONLY, DARK_JEDI_ONLY, FACTION_REBEL, FACTION_IMPERIAL };

	CloningBuildingObjectTemplate();

	~CloningBuildingObjectTemplate();

	void readObject(LuaObject* templateData);

	CloneSpawnPoint* getRandomSpawnPoint();

	bool isCloningBuildingObjectTemplate();

	int getFacilityType();

	bool isJediCloner();

	Vector<CloneSpawnPoint>* getCloneSpawnPoints();
};

} // namespace building
} // namespace templates

using namespace templates::building;
