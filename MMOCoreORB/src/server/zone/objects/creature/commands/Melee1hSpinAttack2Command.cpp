#include "Melee1hSpinAttack2Command.h"

Melee1hSpinAttack2Command::Melee1hSpinAttack2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int Melee1hSpinAttack2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	return doCombatAction(creature, target);
}