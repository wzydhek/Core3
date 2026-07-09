#include "FlameSingle1Command.h"

FlameSingle1Command::FlameSingle1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FlameSingle1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (weapon == nullptr || !weapon->isFlameThrower()) {
		return INVALIDWEAPON;
	}

	return doCombatAction(creature, target);
}