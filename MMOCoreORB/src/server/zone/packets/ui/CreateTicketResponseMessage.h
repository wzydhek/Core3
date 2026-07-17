/*
 * CreateTicketResponseMessage.h
 *
 *  Created on: Nov 22, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class CreateTicketResponseMessage : public BaseMessage {
public:
	CreateTicketResponseMessage(int unknown = 0);
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
