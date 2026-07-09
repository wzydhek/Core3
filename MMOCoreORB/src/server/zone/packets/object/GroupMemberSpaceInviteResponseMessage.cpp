#include "GroupMemberSpaceInviteResponseMessage.h"

GroupMemberSpaceInviteResponseMessage::GroupMemberSpaceInviteResponseMessage(CreatureObject* memberCreo, CreatureObject* pilot, byte decision) : ObjectControllerMessage(pilot->getObjectID(), 0x1B, 0x439) {
	if (pilot == nullptr || memberCreo == nullptr)
		return;

	// Member Responding to Invite
	insertLong(memberCreo->getObjectID());
	// The group members decision
	insertByte(decision);
	// Pilot
	insertLong(pilot->getObjectID());
}