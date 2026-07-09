/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/group/GroupObject.h"

class GroupObjectMessage6 : public BaseLineMessage, public Logger {
	GroupObject* group;

public:
	GroupObjectMessage6(GroupObject* gr);

	void insertMembers();
};
