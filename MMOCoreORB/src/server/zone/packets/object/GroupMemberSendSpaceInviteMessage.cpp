#include "GroupMemberSendSpaceInviteMessage.h"

GroupMemberSendSpaceInviteMessage::GroupMemberSendSpaceInviteMessage(CreatureObject* pilot, CreatureObject* memberCreo) : ObjectControllerMessage(memberCreo->getObjectID(), 0x1B, 0x437) {
	if (pilot == nullptr || memberCreo == nullptr)
		return;

	// Pilot Inviting
	insertLong(pilot->getObjectID());
	// Spacer
	insertInt(0x0);
	// Invited Group Member
	insertLong(memberCreo->getObjectID());
}