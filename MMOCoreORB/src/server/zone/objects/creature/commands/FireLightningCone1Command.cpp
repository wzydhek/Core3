#include "FireLightningCone1Command.h"

FireLightningCone1Command::FireLightningCone1Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FireLightningCone1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<WeaponObject*> weapon = creature->getWeapon();

	if (weapon == nullptr || !weapon->isLightningRifle()) {
		return INVALIDWEAPON;
	}

	return doCombatAction(creature, target);
}