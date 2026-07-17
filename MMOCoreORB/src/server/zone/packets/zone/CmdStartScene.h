/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace zone {

class CmdStartScene : public BaseMessage {
public:
	CmdStartScene(CreatureObject* creo);

	static void parse(Packet* pack);
}; // Class Start Scene

} // namespace zone
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::zone;
