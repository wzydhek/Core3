#include "FireAcidCone2Command.h"

FireAcidCone2Command::FireAcidCone2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FireAcidCone2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (!weapon->isHeavyAcidRifle())
		return INVALIDWEAPON;

	return doCombatAction(creature, target);
}