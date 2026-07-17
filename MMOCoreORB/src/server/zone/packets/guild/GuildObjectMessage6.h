/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace guild {

class GuildObjectMessage6 : public BaseLineMessage {
public:
	GuildObjectMessage6(uint64 oid);
};

} // namespace guild
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::guild;
