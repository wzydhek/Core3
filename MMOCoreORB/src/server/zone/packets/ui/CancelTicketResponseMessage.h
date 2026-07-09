/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

class CancelTicketResponseMessage : public BaseMessage {
public:
	CancelTicketResponseMessage(uint32 ticketid, bool success);

};
