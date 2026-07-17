/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace auction {

class IsVendorOwnerResponseMessage : public BaseMessage {

public:
	IsVendorOwnerResponseMessage(SceneObject* vendor, CreatureObject* player, const String& planet, const String& region);

};

} // namespace auction
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::auction;
