/*
 * GuildObjectDeltaMessage3.h
 *
 *  Created on: Oct 29, 2010
 *      Author: crush
 */

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/guild/GuildObject.h"

class GuildObjectDeltaMessage3 : public DeltaMessage {
public:
	GuildObjectDeltaMessage3(uint64 oid);

	void addGuild(GuildObject* guild);

	void removeGuild(GuildObject* guild);

	void removeAllGuilds();
};
