#include "SaberPolearmHit1Command.h"

SaberPolearmHit1Command::SaberPolearmHit1Command(const String& name, ZoneProcessServer* server) : JediCombatQueueCommand(name, server) {
}

int SaberPolearmHit1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	return doCombatAction(creature, target);
}