#include "VolleyFireAttackCommand.h"

VolleyFireAttackCommand::VolleyFireAttackCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int VolleyFireAttackCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	//@TODO: SkillMod 'volleyfire' has no effect atm. Description implies increased chance of volleyfire working, yet volleyfire is not reported to have had a fail chance
	// Possible solution: Increased to-hit-chance through skill mod. Extend if proof is brought.

	return doCombatAction(creature, target);
}