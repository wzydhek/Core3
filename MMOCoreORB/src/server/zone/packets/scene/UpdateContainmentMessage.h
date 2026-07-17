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

class UpdateContainmentMessage : public BaseMessage {
public:
	UpdateContainmentMessage(SceneObject* object, SceneObject* container, uint32 type);

	UpdateContainmentMessage(uint64 object, uint64 container, uint32 type);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
