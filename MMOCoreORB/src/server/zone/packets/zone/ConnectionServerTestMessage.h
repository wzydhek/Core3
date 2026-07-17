/*
 * ConnectionServerMessage.h
 *
 *  Created on: Nov 25, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class ConnectionServerTestMessage : public BaseMessage {
public:
	ConnectionServerTestMessage();

};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
