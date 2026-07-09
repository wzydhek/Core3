#include "FireAcidSingle1Command.h"

FireAcidSingle1Command::FireAcidSingle1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FireAcidSingle1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (!weapon->isHeavyAcidRifle())
		return INVALIDWEAPON;

	return doCombatAction(creature, target);
}