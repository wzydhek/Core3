/*
 * SpawnGroup.h
 *
 *  Created on: Nov 3, 2010
 *      Author: da
 */

#pragma once

#include "LairSpawn.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class SpawnGroup : public Object {
protected:
	String templateName;

	int minLevelCeiling;

	Vector<Reference<LairSpawn*> > spawnList;

public:
	SpawnGroup();

	SpawnGroup(const String& tempName, LuaObject& group);

	SpawnGroup(const SpawnGroup& gr);

	virtual ~SpawnGroup();

	SpawnGroup& operator=(const SpawnGroup& gr);

	const String& getTemplateName() const;

	const Vector<Reference<LairSpawn*>>& getSpawnList();

	void setTemplateName(const String& templateName);

	int getMinLevelCeiling() const;
};

}
}
}
}

using namespace server::zone::managers::creature;
