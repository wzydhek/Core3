
#pragma once

#include "engine/service/proto/BaseMessage.h"

class GetTicketsResponseMessage : public BaseMessage {
	int ticketCount;
public:
	GetTicketsResponseMessage();

   void addTicket(const String& name, const UnicodeString& body, uint32 ticketid, uint64 timeStamp, bool read, bool open);

   void updateCount();
};
