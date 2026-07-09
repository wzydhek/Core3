#include "UnarmedCombo1Command.h"

UnarmedCombo1Command::UnarmedCombo1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedCombo1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	float healthmod = (90.f - (float)System::random(50)) / 100.f;
	float actionmod = 0.1f;
	float mindmod = 1.f - healthmod - actionmod;

	UnicodeString args = "healthDamageMultiplier=" + String::valueOf(healthmod) + ";actionDamageMultiplier=" + String::valueOf(actionmod) + ";mindDamageMultiplier=" + String::valueOf(mindmod) + ";";

	return doCombatAction(creature, target, args);
}