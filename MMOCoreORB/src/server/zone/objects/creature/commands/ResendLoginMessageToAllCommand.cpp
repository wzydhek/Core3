#include "ResendLoginMessageToAllCommand.h"
#include "server/zone/managers/player/PlayerManager.h"

ResendLoginMessageToAllCommand::ResendLoginMessageToAllCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ResendLoginMessageToAllCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

	if (playerManager != nullptr)
		playerManager->resendLoginMessageToAll();

	return SUCCESS;
}