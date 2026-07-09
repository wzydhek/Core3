#include "DisbandCommand.h"
#include "server/zone/objects/group/GroupObject.h"
#include "server/zone/managers/group/GroupManager.h"

DisbandCommand::DisbandCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int DisbandCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	GroupManager* groupManager = GroupManager::instance();

	ManagedReference<GroupObject*> group = creature->getGroup();

	if (group == nullptr)
		return GENERALERROR;

	// If player not is leader, he will leave the group instead.
	// Fix 13 feb 2009 - Bankler
	if (creature != group->getLeader())
		groupManager->leaveGroup(group.get(), creature);
	else
		groupManager->disbandGroup(group.get(), creature);

	return SUCCESS;
}