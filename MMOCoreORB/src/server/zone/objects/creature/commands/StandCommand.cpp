#include "StandCommand.h"

StandCommand::StandCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int StandCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature)) {
		return INVALIDSTATE;
	}

	if (!checkInvalidLocomotions(creature)) {
		if (creature->isFeigningDeath() && !creature->hasIncapTimer()) {
			creature->removeFeignedDeath();
			creature->setPosture(CreaturePosture::KNOCKEDDOWN, false, true);
			// Allow us to pass the state/locomotion checks below, but still enter dizzy/KD checks
		} else {
			return INVALIDLOCOMOTION;
		}
	}

	if (creature->isAiAgent()) {
		return setAiAgentPosture(creature);
	}

	if (creature->isPlayerCreature()) {
		return setPlayerPosture(creature);
	}

	creature->setPosture(CreaturePosture::UPRIGHT);
	return SUCCESS;
}

int StandCommand::setAiAgentPosture(CreatureObject* creature) const {
	if (creature->isNonPlayerCreatureObject() && creature->isDizzied() && System::random(100) < 85) {
		creature->queueDizzyFallEvent();
		return SUCCESS;
	}

	creature->setPosture(CreaturePosture::UPRIGHT);
	return SUCCESS;
}

int StandCommand::setPlayerPosture(CreatureObject* creature) const {
	const String& commandName = getQueueCommandName();

	if (creature->getQueueCommandDeltaTime(commandName) < StandCommand::MINDELTA) {
		return GENERALERROR;
	}

	if (creature->isDizzied() && System::random(100) < 85) {
		creature->queueDizzyFallEvent();
		return SUCCESS;
	}

	creature->setQueueCommandDeltaTime(commandName, "setPosture");
	creature->setPosture(CreaturePosture::UPRIGHT);
	return SUCCESS;
}