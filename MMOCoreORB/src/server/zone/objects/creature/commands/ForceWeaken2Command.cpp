#include "ForceWeaken2Command.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/buffs/ForceWeakenDebuff.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/combat/CombatManager.h"

ForceWeaken2Command::ForceWeaken2Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceWeaken2Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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

	CreatureObject* creatureTarget = targetObject.castTo<CreatureObject*>();

	if (creatureTarget->hasBuff(STRING_HASHCODE("forceweaken1")) || creatureTarget->hasBuff(STRING_HASHCODE("forceweaken2"))) {
		return ALREADYAFFECTEDJEDIPOWER;
	}

	int res = doCombatAction(creature, target);

	if (res == SUCCESS) {
		Locker clocker(creatureTarget, creature);

		ManagedReference<Buff*> buff = new ForceWeakenDebuff(creatureTarget, getNameCRC(), 400, 600, 120);

		Locker locker(buff);

		creatureTarget->addBuff(buff);

		CombatManager::instance()->broadcastCombatSpam(creature, creatureTarget, nullptr, 0, "cbt_spam", combatSpam + "_hit", 1);
	}

	return res;
}