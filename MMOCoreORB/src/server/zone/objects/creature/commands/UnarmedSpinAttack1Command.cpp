#include "UnarmedSpinAttack1Command.h"

UnarmedSpinAttack1Command::UnarmedSpinAttack1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedSpinAttack1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}