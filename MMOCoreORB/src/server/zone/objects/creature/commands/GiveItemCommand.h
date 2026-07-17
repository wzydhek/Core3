/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#include "QueueCommand.h"
#include "server/zone/objects/tangible/TangibleObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace commands {

class GiveItemCommand : public QueueCommand {
public:
	GiveItemCommand(const String& name, ZoneProcessServer* server);

	int doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const;

	bool giveItemToVendor(CreatureObject* player, CreatureObject* vendor, TangibleObject* giveItem) const;

	bool giveItemToActorNpc(CreatureObject* player, CreatureObject* npcActor, TangibleObject* giveItem) const;
};

} // namespace commands
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::commands;
