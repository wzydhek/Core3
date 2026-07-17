/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class CancelTicketResponseMessage : public BaseMessage {
public:
	CancelTicketResponseMessage(uint32 ticketid, bool success);

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
