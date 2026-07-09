#include "SpatialChatInternalCommand.h"
#include "server/chat/ChatManager.h"

SpatialChatInternalCommand::SpatialChatInternalCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SpatialChatInternalCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	ChatManager* chatManager = server->getChatManager();
	if (chatManager == nullptr)
		return GENERALERROR;

	chatManager->handleSpatialChatInternalMessage(creature, arguments);

	return SUCCESS;
}