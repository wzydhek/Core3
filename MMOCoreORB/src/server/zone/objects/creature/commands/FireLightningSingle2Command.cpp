#include "FireLightningSingle2Command.h"

FireLightningSingle2Command::FireLightningSingle2Command(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int FireLightningSingle2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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