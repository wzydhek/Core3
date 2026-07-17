/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "LightUpdateTransformMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class LightUpdateTransformWithParentMessage : public UNRELIABLE_LIGHT_BASE_CLASS {
public:
	LightUpdateTransformWithParentMessage(SceneObject* object);

	LightUpdateTransformWithParentMessage(SceneObject* object, float posX, float posZ, float posY, uint64 cellID);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
