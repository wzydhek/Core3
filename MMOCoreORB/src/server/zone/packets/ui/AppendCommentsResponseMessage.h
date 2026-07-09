/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class AppendCommentsResponseMessage : public BaseMessage {
public:
	AppendCommentsResponseMessage(uint32 ticketid, bool success);

};
