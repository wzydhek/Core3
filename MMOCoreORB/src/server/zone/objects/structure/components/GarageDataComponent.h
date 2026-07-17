/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "system/util/SynchronizedSortedVector.h"

namespace server {
namespace zone {
namespace objects {
namespace structure {
namespace components {

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

} // namespace components
} // namespace structure
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::structure::components;
