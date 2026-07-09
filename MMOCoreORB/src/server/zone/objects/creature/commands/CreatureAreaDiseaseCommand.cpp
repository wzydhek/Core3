#include "CreatureAreaDiseaseCommand.h"

CreatureAreaDiseaseCommand::CreatureAreaDiseaseCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int CreatureAreaDiseaseCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isAiAgent())
		return GENERALERROR;

	return doCombatAction(creature, target, arguments);
}