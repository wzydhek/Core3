/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForcePowersQueueCommand.h"
#include "server/zone/objects/creature/buffs/Buff.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/visibility/VisibilityManager.h"
#include "server/zone/objects/creature/buffs/SingleUseBuff.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/managers/frs/FrsManager.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class JediMindTrickCommand : public ForcePowersQueueCommand {
public:

	JediMindTrickCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
