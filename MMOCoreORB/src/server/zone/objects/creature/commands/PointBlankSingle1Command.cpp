#include "PointBlankSingle1Command.h"

PointBlankSingle1Command::PointBlankSingle1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int PointBlankSingle1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS)
		creature->notifyObservers(ObserverEventType::ABILITYUSED, nullptr, STRING_HASHCODE("pointblanksingle1"));

	return result;
}