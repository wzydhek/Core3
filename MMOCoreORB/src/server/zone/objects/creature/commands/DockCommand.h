/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "SpaceQueueCommand.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class DockCommand : public SpaceQueueCommand {
private:
	constexpr static float DOCKING_RANGE = 200.f;

public:
	DockCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

private:
	bool getDockingPermission(ShipObject* ship, ShipObject* target) const;

	void setDocking(ShipObject* ship, ShipObject* target) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
