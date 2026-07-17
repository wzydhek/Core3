/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class SceneObjectCreateMessage : public BaseMessage {
public:
	SceneObjectCreateMessage(const SceneObject* scno);

	SceneObjectCreateMessage(uint64 oid, uint32 objCrc);

	static void parseMessage(Message* pack, SceneObject* scno);
};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
