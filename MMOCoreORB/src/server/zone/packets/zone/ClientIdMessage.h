/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ClientIdMessage : public BaseMessage {
public:
	ClientIdMessage(uint32 accountID, const String& sessionID);
};
