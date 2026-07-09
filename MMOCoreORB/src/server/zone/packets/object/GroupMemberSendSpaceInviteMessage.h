/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class GroupMemberSendSpaceInviteMessage: public ObjectControllerMessage {
public:
	GroupMemberSendSpaceInviteMessage(CreatureObject* pilot, CreatureObject* memberCreo);

};
