/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class SelectCharacter : public BaseMessage {
public:
	SelectCharacter(uint64 characterID);

	static uint64 parse(Packet* pack);
};

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
