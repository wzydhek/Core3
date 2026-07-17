/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class GroupMemberSpaceInviteResponseMessage: public ObjectControllerMessage {
public:
	GroupMemberSpaceInviteResponseMessage(CreatureObject* memberCreo, CreatureObject* pilot, byte decision);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
