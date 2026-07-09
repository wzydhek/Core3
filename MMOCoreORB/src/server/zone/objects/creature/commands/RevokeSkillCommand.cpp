#include "RevokeSkillCommand.h"
#include "server/zone/ZoneServer.h"
#include "server/zone/managers/skill/SkillManager.h"

RevokeSkillCommand::RevokeSkillCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int RevokeSkillCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<SceneObject*> object = server->getZoneServer()->getObject(target);

	if (object == nullptr || !object->isPlayerCreature())
		return INVALIDTARGET;

	CreatureObject* targetCreature = object->asCreatureObject();

	if (targetCreature == nullptr)
		return GENERALERROR;

	String skillString = arguments.toString();

	if (!targetCreature->hasSkill(skillString)) {
		creature->sendSystemMessage(targetCreature->getFirstName() + " does not have the skill: " + skillString);
		return GENERALERROR;
	}

	Locker clocker(targetCreature, creature);

	SkillManager* skillManager = SkillManager::instance();

	if (skillManager == nullptr)
		return GENERALERROR;

	if (skillManager->surrenderSkill(skillString, targetCreature, true, true, true)) {
		creature->sendSystemMessage("Successfully revoked skill: " + skillString + " from player " + targetCreature->getFirstName());
		targetCreature->sendSystemMessage("Skill: " + skillString + " has been revoked.");
	}

	return SUCCESS;
}