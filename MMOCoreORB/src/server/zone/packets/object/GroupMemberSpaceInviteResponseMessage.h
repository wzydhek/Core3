/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class GroupMemberSpaceInviteResponseMessage: public ObjectControllerMessage {
public:
	GroupMemberSpaceInviteResponseMessage(CreatureObject* memberCreo, CreatureObject* pilot, byte decision);

};
