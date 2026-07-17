/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace packets {
namespace group {

class GroupObjectMessage6 : public BaseLineMessage, public Logger {
	GroupObject* group;

public:
	GroupObjectMessage6(GroupObject* gr);

	void insertMembers();
};

} // namespace group
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::group;
