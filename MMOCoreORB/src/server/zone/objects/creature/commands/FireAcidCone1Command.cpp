#include "FireAcidCone1Command.h"

FireAcidCone1Command::FireAcidCone1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FireAcidCone1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (!weapon->isHeavyAcidRifle())
		return INVALIDWEAPON;

	return doCombatAction(creature, target);
}