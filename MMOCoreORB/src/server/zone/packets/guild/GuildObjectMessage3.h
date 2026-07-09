/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/scene/variables/DeltaSet.h"
#include "server/zone/objects/guild/GuildObject.h"

class GuildObjectMessage3 : public BaseLineMessage {
public:
	GuildObjectMessage3(DeltaSet<String, ManagedReference<GuildObject*>>* guildList, uint64 oid);
};
