#include "ClaimVeteranRewardCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/player/PlayerManager.h"

ClaimVeteranRewardCommand::ClaimVeteranRewardCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ClaimVeteranRewardCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	PlayerManager* playerManager = creature->getZoneServer()->getPlayerManager();

	if (playerManager == nullptr)
		return GENERALERROR;

	playerManager->claimVeteranRewards(creature);

	return SUCCESS;
}