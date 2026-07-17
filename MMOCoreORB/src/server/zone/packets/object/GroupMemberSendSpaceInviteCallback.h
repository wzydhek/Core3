/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class GroupMemberSendSpaceInviteCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;
	uint64 groupMemberID;

public:
	GroupMemberSendSpaceInviteCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
