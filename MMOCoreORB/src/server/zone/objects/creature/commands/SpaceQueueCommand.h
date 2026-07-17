#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class SpaceQueueCommand : public QueueCommand {
public:
	SpaceQueueCommand(const String& skillname, ZoneProcessServer* serv);

	ManagedReference<ShipObject*> getPlayerShip(CreatureObject* creature) const;

	ManagedReference<ShipObject*> getShipTarget(ShipObject* ship) const;

	bool isInRange(ShipObject* ship, ShipObject* target, float distance) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
