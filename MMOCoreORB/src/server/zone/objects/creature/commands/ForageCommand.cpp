#include "ForageCommand.h"
#include "server/zone/managers/minigames/ForageManager.h"

ForageCommand::ForageCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int ForageCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPlayerCreature())
		return GENERALERROR;

	if (creature->isPlayerCreature()) {
		CreatureObject* player = cast<CreatureObject*>(creature);
		ForageManager* forageManager = server->getForageManager();
		forageManager->startForaging(player, ForageManager::SCOUT);
	}

	return SUCCESS;
}