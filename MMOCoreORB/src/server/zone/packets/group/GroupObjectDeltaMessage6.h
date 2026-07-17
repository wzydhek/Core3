/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/group/GroupObject.h"

namespace server {
namespace zone {
namespace packets {
namespace group {

class GroupObjectDeltaMessage6 : public DeltaMessage, public Logger {
	GroupObject* group;

public:
	GroupObjectDeltaMessage6(GroupObject* gr);

	void initialUpdate();

	void updateMembers();

	void updateLevel(uint16 value);

	void updateLootRules(uint64 looter, int rule);
};

} // namespace group
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::group;
