/*
 * VerifyPlayerNameResponseMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class VerifyPlayerNameResponseMessage : public BaseMessage {
public:
	VerifyPlayerNameResponseMessage(bool success);

};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
