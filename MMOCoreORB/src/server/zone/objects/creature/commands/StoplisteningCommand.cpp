#include "StoplisteningCommand.h"
#include "server/zone/managers/player/PlayerManager.h"

StoplisteningCommand::StoplisteningCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int StoplisteningCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isListening())
		return GENERALERROR;

	ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

	if (playerManager != nullptr)
		playerManager->stopListen(creature, target);

	return SUCCESS;
}