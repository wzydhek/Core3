#include "PeaceCommand.h"
#include "server/zone/managers/combat/CombatManager.h"

PeaceCommand::PeaceCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int PeaceCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	creature->clearQueueActions(true);

	CombatManager::instance()->attemptPeace(creature);

	return SUCCESS;
}