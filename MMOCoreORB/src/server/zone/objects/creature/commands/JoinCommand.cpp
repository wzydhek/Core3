#include "JoinCommand.h"
#include "server/zone/managers/group/GroupManager.h"

JoinCommand::JoinCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int JoinCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (creature->isGrouped())
		return GENERALERROR;

	Reference<CreatureObject*> creatureRef = creature;

	Core::getTaskManager()->executeTask(
		[creatureRef]() {
			if (creatureRef == nullptr)
				return;

			GroupManager* groupManager = GroupManager::instance();

			if (groupManager == nullptr)
				return;

			groupManager->joinGroup(creatureRef);
		},
		"JoinGroupLambda");

	return SUCCESS;
}