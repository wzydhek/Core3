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

class UpdateTransformWithParentMessage : public BaseMessage {
public:
	UpdateTransformWithParentMessage(SceneObject* object);
	
	UpdateTransformWithParentMessage(SceneObject* object, float posX, float posZ, float posY, uint64 parentID);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
