#include "FishCommand.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/minigames/FishingManager.h"

FishCommand::FishCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int FishCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature)) {
		return INVALIDLOCOMOTION;
	}

	if (!creature->isPlayerCreature()) {
		return GENERALERROR;
	}

	auto fishingManager = server->getFishingManager();

	if (fishingManager == nullptr) {
		return GENERALERROR;
	}

	if (fishingManager->getFishingState(creature) != FishingManager::NOTFISHING) {
		return GENERALERROR;
	}

	fishingManager->startFishing(creature);

	return SUCCESS;
}