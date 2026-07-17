/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class GroupMemberSpaceInviteResponseCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;
	uint64 pilotID;
	byte decision;

public:
	GroupMemberSpaceInviteResponseCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
