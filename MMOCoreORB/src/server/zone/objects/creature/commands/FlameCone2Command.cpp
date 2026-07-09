#include "FlameCone2Command.h"

FlameCone2Command::FlameCone2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FlameCone2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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