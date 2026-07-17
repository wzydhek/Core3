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

class GroupMemberSendSpaceInviteMessage: public ObjectControllerMessage {
public:
	GroupMemberSendSpaceInviteMessage(CreatureObject* pilot, CreatureObject* memberCreo);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
