
#pragma once

#include "server/zone/objects/creature/commands/QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {
namespace pet {

class PetThrowCommand : public QueueCommand {
public:
	PetThrowCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& targetID, const UnicodeString& arguments) const;
};

} // namespace pet
} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands::pet;
