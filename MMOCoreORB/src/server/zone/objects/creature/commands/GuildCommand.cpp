#include "GuildCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"

GuildCommand::GuildCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GuildCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ChatManager* chatManager = server->getZoneServer()->getChatManager();
	chatManager->handleGuildChat(creature, arguments);

	return SUCCESS;
}