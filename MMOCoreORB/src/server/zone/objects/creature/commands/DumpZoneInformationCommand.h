/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "QueueCommand.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/Zone.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class DumpZoneInformationCommand : public QueueCommand {
public:

	DumpZoneInformationCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	int dumpGroundZone(CreatureObject* creature, Zone* zone) const;

	int dumpSpaceZone(CreatureObject* creature, Zone* zone) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
