#include "WatchCommand.h"
#include "server/zone/managers/player/PlayerManager.h"

WatchCommand::WatchCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int WatchCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (creature->isWatching())
		return GENERALERROR;

	ManagedReference<PlayerManager*> playerManager = server->getPlayerManager();

	if (playerManager != nullptr)
		playerManager->startWatch(creature, target);

	return SUCCESS;
}