/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class GroupMemberSendSpaceInviteMessage: public ObjectControllerMessage {
public:
	GroupMemberSendSpaceInviteMessage(CreatureObject* pilot, CreatureObject* memberCreo) : ObjectControllerMessage(memberCreo->getObjectID(), 0x1B, 0x437) {
		if (pilot == nullptr || memberCreo == nullptr)
			return;

		// Pilot Inviting
		insertLong(pilot->getObjectID());
		// Spacer
		insertInt(0x0);
		// Invited Group Member
		insertLong(memberCreo->getObjectID());
	}

};
