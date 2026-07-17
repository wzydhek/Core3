/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/region/Region.h"

namespace server {
namespace zone {
namespace managers {
namespace planet {

class NoBuildAreaMap : public Object {
	Vector<ManagedReference<Region*> > areas;

public:
	NoBuildAreaMap();

	~NoBuildAreaMap();

	bool add(Region* region);

	bool isNoBuildZone(float x, float y, StringId& fullAreaName);
};

} // namespace planet
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::planet;
