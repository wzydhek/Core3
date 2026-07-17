/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace charcreation {

class ClientRandomNameResponse : public BaseMessage {
public:
	ClientRandomNameResponse(String raceIff, String name);
	
};

} // namespace charcreation
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::charcreation;
