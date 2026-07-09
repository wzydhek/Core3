/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/group/GroupObject.h"

class GroupObjectMessage3 : public BaseLineMessage, public Logger {
public:
	GroupObjectMessage3(GroupObject* grup);
};
