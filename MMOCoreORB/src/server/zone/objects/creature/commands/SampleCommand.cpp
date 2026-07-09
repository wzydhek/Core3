#include "SampleCommand.h"

SampleCommand::SampleCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SampleCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		if (creature->isPlayerCreature() && creature->isInCombat()) {
			creature->sendSystemMessage("@survey:sample_cancel_attack"); // You can't take samples while under attack!
		}

		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return SUCCESS;
}