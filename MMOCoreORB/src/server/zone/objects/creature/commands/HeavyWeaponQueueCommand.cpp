#include "HeavyWeaponQueueCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/combat/CreatureAttackData.h"
#include "server/zone/managers/collision/CollisionManager.h"

HeavyWeaponQueueCommand::HeavyWeaponQueueCommand(const String& name, ZoneProcessServer* server) : CombatQueueCommand(name, server) {
}

int HeavyWeaponQueueCommand::doCombatAction(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	ManagedReference<SceneObject*> targetObject = server->getZoneServer()->getObject(target);

	if (targetObject == nullptr || !targetObject->isTangibleObject() || targetObject == creature)
		return INVALIDTARGET;

	if (creature->isProne())
		return NOPRONE;

	if (!checkDistance(creature, targetObject, range))
		return TOOFAR;

	if (!CollisionManager::checkLineOfSight(creature, targetObject)) {
		creature->sendSystemMessage("@cbt_spam:los_fail"); // You lost sight of your target.
		return GENERALERROR;
	}

	CombatManager* combatManager = CombatManager::instance();

	try {
		int res = combatManager->doCombatAction(creature, creature->getWeapon(), cast<TangibleObject*>(targetObject.get()), CreatureAttackData(arguments, this, target));

		switch (res) {
			case -1:
				return INVALIDTARGET;
			case -3:
				return GENERALERROR;
		}
	} catch (Exception& e) {
		error("unreported exception caught in HeavyWeaponQueueCommand::doCombatAction");
		error(e.getMessage());
		e.printStackTrace();
	}
	return SUCCESS;
}

float HeavyWeaponQueueCommand::getCommandDuration(CreatureObject* object, const UnicodeString& arguments) const {
	return defaultTime * speed;
}