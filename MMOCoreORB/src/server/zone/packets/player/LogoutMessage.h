/*
 * LogoutMessage.h
 *
 *  Created on: Nov 20, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class LogoutMessage : public BaseMessage {
public:
	LogoutMessage();

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
