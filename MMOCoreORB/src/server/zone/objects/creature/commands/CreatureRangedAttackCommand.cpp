#include "CreatureRangedAttackCommand.h"

CreatureRangedAttackCommand::CreatureRangedAttackCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int CreatureRangedAttackCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (weapon == nullptr || !weapon->isRangedWeapon()) {
		return INVALIDWEAPON;
	}

	return doCombatAction(creature, target);
}