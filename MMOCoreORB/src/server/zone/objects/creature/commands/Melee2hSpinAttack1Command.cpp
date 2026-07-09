#include "Melee2hSpinAttack1Command.h"

Melee2hSpinAttack1Command::Melee2hSpinAttack1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee2hSpinAttack1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}