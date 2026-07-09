/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/region/Region.h"

class NoBuildAreaMap : public Object {
	Vector<ManagedReference<Region*> > areas;

public:
	NoBuildAreaMap();

	~NoBuildAreaMap();

	bool add(Region* region);

	bool isNoBuildZone(float x, float y, StringId& fullAreaName);
};
