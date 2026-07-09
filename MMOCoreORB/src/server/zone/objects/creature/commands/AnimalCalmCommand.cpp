#include "AnimalCalmCommand.h"
#include "templates/params/creature/ObjectFlag.h"
#include "server/zone/objects/creature/ai/AiAgent.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/combat/CombatManager.h"

AnimalCalmCommand::AnimalCalmCommand(const String& name, ZoneProcessServer* server) : ForcePowersQueueCommand(name, server) {
}

int AnimalCalmCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (isWearingArmor(creature)) {
		return NOJEDIARMOR;
	}

	ZoneServer* zoneServer = creature->getZoneServer();

	if (zoneServer == nullptr)
		return GENERALERROR;

	ManagedReference<SceneObject*> targetObject = zoneServer->getObject(target);

	StringIdChatParameter param;
	param.setStringId("@error_message:target_not_creature");

	if (targetObject == nullptr)
		return GENERALERROR;

	if (!targetObject->isCreatureObject()) {
		creature->sendSystemMessage(param);
		return GENERALERROR;
	}

	CreatureObject* tarCreo = targetObject->asCreatureObject();

	if (tarCreo == nullptr || !tarCreo->isAiAgent() || tarCreo->isNonPlayerCreatureObject()) {
		creature->sendSystemMessage(param);
		return GENERALERROR;
	}

	AiAgent* agent = tarCreo->asAiAgent();

	if (agent == nullptr)
		return GENERALERROR;

	int result = doCombatAction(creature, target);

	if (result == SUCCESS) {
		int playerLevel = creature->getLevel() * 2;
		int targetLevel = tarCreo->getLevel();
		int failCalc = (targetLevel - playerLevel + System::random(250));

		if (agent->getCreatureBitmask() & ObjectFlag::AGGRESSIVE)
			failCalc += 75;

		if (failCalc < 300) {
			CombatManager::instance()->forcePeace(agent);
			param.setStringId("@jedi_spam:calm_target");
		} else {
			param.setStringId("@jedi_spam:fail_calm_target");
		}

		creature->sendSystemMessage(param);
	}

	return result;
}