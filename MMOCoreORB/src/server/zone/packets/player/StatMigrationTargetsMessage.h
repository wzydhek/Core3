/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/player/sessions/MigrateStatsSession.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class StatMigrationTargetsMessage : public BaseMessage {
public:
	StatMigrationTargetsMessage(CreatureObject* creo);

	StatMigrationTargetsMessage(CreatureObject* creo, MigrateStatsSession* stats);

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
