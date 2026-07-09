#include "ListGuildsCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/guild/GuildManager.h"

ListGuildsCommand::ListGuildsCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ListGuildsCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return INVALIDPARAMETERS;

	CreatureObject* player = cast<CreatureObject*>(creature);

	ManagedReference<GuildManager*> guildManager = server->getZoneServer()->getGuildManager();

	guildManager->sendGuildListTo(player, arguments.toString());

	return SUCCESS;
}