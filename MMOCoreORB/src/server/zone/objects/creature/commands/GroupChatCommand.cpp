#include "GroupChatCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"

GroupChatCommand::GroupChatCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int GroupChatCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ChatManager* chatManager = server->getZoneServer()->getChatManager();
	chatManager->handleGroupChat(creature, arguments);

	return SUCCESS;
}