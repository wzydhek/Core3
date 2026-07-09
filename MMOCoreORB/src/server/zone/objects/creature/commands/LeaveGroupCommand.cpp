#include "LeaveGroupCommand.h"
#include "server/zone/managers/group/GroupManager.h"
#include "server/zone/objects/group/GroupObject.h"

LeaveGroupCommand::LeaveGroupCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int LeaveGroupCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	GroupManager* groupManager = GroupManager::instance();

	ManagedReference<GroupObject*> group = creature->getGroup();

	if (group == nullptr)
		return GENERALERROR;

	groupManager->leaveGroup(group.get(), creature);

	return SUCCESS;
}