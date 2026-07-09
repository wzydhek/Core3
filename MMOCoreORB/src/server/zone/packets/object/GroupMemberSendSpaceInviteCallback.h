/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessageCallback.h"

class GroupMemberSendSpaceInviteCallback : public MessageCallback {
	ObjectControllerMessageCallback* objectControllerMain;
	uint64 groupMemberID;

public:
	GroupMemberSendSpaceInviteCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
