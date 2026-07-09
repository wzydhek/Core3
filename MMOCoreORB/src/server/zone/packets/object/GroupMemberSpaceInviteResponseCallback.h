/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessageCallback.h"

class GroupMemberSpaceInviteResponseCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;
	uint64 pilotID;
	byte decision;

public:
	GroupMemberSpaceInviteResponseCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
