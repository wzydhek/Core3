/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class ChatOnChangeIgnoreStatus : public BaseMessage {
public:
	ChatOnChangeIgnoreStatus(uint64 oid, const String& name, const String& server, bool add);

};
