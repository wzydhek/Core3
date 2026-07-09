#include "SetCurrentSkillTitleCommand.h"
#include "server/zone/objects/player/PlayerObject.h"

SetCurrentSkillTitleCommand::SetCurrentSkillTitleCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int SetCurrentSkillTitleCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	ManagedReference<PlayerObject*> ghost = creature->getPlayerObject();

	if (ghost == nullptr)
		return GENERALERROR;

	String titleSkill = arguments.toString().toLowerCase();

	if (!titleSkill.isEmpty() && !creature->hasSkill(titleSkill))
		return GENERALERROR;

	ghost->setTitle(titleSkill, true);

	return SUCCESS;
}