#include "ForceKnockdown2Command.h"
#include "server/zone/ZoneServer.h"

ForceKnockdown2Command::ForceKnockdown2Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceKnockdown2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	ManagedReference<SceneObject*> targetObject = server->getZoneServer()->getObject(target);

	if (targetObject == nullptr || !targetObject->isCreatureObject()) {
		return INVALIDTARGET;
	}

	return doCombatAction(creature, target);
}