/*
 * SpaceSpawnGroup.h
 *
 *  Created on: 2024-09-15
 *  Author: Hakry
 */

#pragma once

#include "SpaceSpawn.h"

namespace server {
namespace zone {
namespace managers {
namespace ship {

class SpaceSpawnGroup : public Object {
protected:
	String templateName;

	Vector<Reference<SpaceSpawn*>> spawnList;

public:
	SpaceSpawnGroup();

	SpaceSpawnGroup(const String& tempName, LuaObject& shipSpawnGroups);

	SpaceSpawnGroup(const SpaceSpawnGroup& gr);

	virtual ~SpaceSpawnGroup();

	SpaceSpawnGroup& operator=(const SpaceSpawnGroup& gr);

	const String& getTemplateName() const;

	const Vector<Reference<SpaceSpawn*>>& getSpawnList();

	void setTemplateName(const String& templateName);
};

} // namespace ship
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::ship;
