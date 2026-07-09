#include "ForceIntimidate1Command.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/events/ForceIntimidateTask.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/combat/CombatManager.h"

ForceIntimidate1Command::ForceIntimidate1Command(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int ForceIntimidate1Command::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
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

	CreatureObject* tarCreo = targetObject->asCreatureObject();

	if (tarCreo == nullptr)
		return GENERALERROR;

	int res = doCombatAction(creature, target);

	if (res == SUCCESS) {
		CreatureAttackData data = CreatureAttackData("", this, target);
		Reference<SortedVector<ManagedReference<TangibleObject*>>*> targets = CombatManager::instance()->getAreaTargets(creature, creature->getWeapon(), tarCreo, data);
		if (targets->size() != 0) {
			ForceIntimidateTask* task = new ForceIntimidateTask(tarCreo, targets, this);
			task->schedule(1500);
		}
	}

	return res;
}