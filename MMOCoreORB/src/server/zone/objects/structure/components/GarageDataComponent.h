/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "system/util/SynchronizedSortedVector.h"

class GarageDataComponent : public DataObjectComponent {
protected:
	SynchronizedSortedVector<uint64> notifiedPlayers;

public:
	GarageDataComponent();

	~GarageDataComponent();

	bool hasNotifiedPlayer(const uint64 oid);

	void addNotifiedPlayer(const uint64 oid);

	void removeNotifiedPlayer(const uint64 oid);
};
