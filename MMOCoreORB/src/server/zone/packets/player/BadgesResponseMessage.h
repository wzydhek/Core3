/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/badges/Badges.h"

namespace server {
namespace zone {
namespace packets {
namespace player {

class BadgesResponseMessage : public BaseMessage {
public:
	BadgesResponseMessage(SceneObject* player, Badges* badges);

};

} // namespace player
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::player;
