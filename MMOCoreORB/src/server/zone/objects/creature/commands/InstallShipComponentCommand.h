/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class InstallShipComponentCommand : public QueueCommand {
public:

	InstallShipComponentCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool isSlotCompatibleWithComponent(ShipObject* ship, ShipComponent* component, uint32 slot) const;

	bool isPlayerCertifiedForObject(CreatureObject* player, TangibleObject* object) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
