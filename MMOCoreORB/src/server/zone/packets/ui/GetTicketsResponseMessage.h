
#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class GetTicketsResponseMessage : public BaseMessage {
	int ticketCount;
public:
	GetTicketsResponseMessage();

   void addTicket(const String& name, const UnicodeString& body, uint32 ticketid, uint64 timeStamp, bool read, bool open);

   void updateCount();
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
