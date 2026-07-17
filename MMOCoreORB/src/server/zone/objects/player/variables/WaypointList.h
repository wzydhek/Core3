/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/scene/variables/DeltaVectorMap.h"
#include "server/zone/objects/waypoint/WaypointObject.h"

namespace server {
namespace zone {
namespace objects {
namespace player {
namespace variables {

class WaypointList : public DeltaVectorMap<uint64, ManagedReference<WaypointObject*> > {
public:

	int set(uint64 key, WaypointObject* value, DeltaMessage* message = nullptr, int updates = 1);

	friend void to_json(nlohmann::json& j, const WaypointList& w);

	bool drop(const uint64& key, DeltaMessage* message = nullptr, int updates = 1) override;

	bool update(const uint64& key, DeltaMessage* message, int updates = 1);

	void insertToMessage(BaseMessage* msg) const override;

	uint64 find(const String& name) const;

	uint64 getWaypointBySpecialType(const uint8 specialTypeID) const;

	WaypointObject* getWaypointAt(float x, float y, String planet) const;
};

} // namespace variables
} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player::variables;
