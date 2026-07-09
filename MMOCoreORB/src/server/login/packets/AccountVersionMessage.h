/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class AccountVersionMessage : public BaseMessage {

public:
	AccountVersionMessage(const String& username, const String& password, const String& version);

	static void parse(Packet* pack, String& username, String& password, String& version);

};
