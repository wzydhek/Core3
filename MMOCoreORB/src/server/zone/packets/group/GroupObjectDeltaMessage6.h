/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/group/GroupObject.h"

class GroupObjectDeltaMessage6 : public DeltaMessage, public Logger {
	GroupObject* group;

public:
	GroupObjectDeltaMessage6(GroupObject* gr);

	void initialUpdate();

	void updateMembers();

	void updateLevel(uint16 value);

	void updateLootRules(uint64 looter, int rule);
};
