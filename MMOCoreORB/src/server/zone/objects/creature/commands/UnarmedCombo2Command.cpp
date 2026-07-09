#include "UnarmedCombo2Command.h"

UnarmedCombo2Command::UnarmedCombo2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int UnarmedCombo2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	float healthmod = System::random(70) + 10;
	float actionmod = System::random(70) + 10;
	float mindmod = System::random(70) + 10;

	int total = healthmod + actionmod + mindmod;

	healthmod /= total;
	actionmod /= total;
	mindmod /= total;

	UnicodeString args = "healthDamageMultiplier=" + String::valueOf(healthmod) + ";actionDamageMultiplier=" + String::valueOf(actionmod) + ";mindDamageMultiplier=" + String::valueOf(mindmod) + ";";

	return doCombatAction(creature, target, args);
}