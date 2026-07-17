/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class ClientLogout : public BaseMessage {
public:
	ClientLogout();
	
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
