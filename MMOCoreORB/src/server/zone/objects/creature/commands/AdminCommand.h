#pragma once

#include "QueueCommand.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class AdminCommand : public QueueCommand {

public:
	AdminCommand(const String& skillName, ZoneProcessServer* serv);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
