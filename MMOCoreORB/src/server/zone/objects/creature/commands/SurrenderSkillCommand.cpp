#include "SurrenderSkillCommand.h"
#include "server/zone/managers/skill/SkillManager.h"

SurrenderSkillCommand::SurrenderSkillCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SurrenderSkillCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	SkillManager* skillManager = SkillManager::instance();

	if (skillManager == nullptr) {
		return GENERALERROR;
	}

	skillManager->surrenderSkill(arguments.toString(), creature, true);

	return SUCCESS;
}