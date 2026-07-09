#include "AuctionsayCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/chat/ChatManager.h"

AuctionsayCommand::AuctionsayCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int AuctionsayCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ChatManager* chatManager = server->getZoneServer()->getChatManager();
	chatManager->handleAuctionChat(creature, arguments);

	return SUCCESS;
}