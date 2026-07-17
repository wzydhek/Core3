/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/scene/variables/DeltaSet.h"
#include "server/zone/objects/guild/GuildObject.h"

namespace server {
namespace zone {
namespace packets {
namespace guild {

class GuildObjectMessage3 : public BaseLineMessage {
public:
	GuildObjectMessage3(DeltaSet<String, ManagedReference<GuildObject*>>* guildList, uint64 oid);
};

} // namespace guild
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::guild;
