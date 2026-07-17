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

class UpdateTransformMessage : public BaseMessage {
public:
	UpdateTransformMessage(SceneObject* scno);

	UpdateTransformMessage(SceneObject* scno, float posX, float posZ, float posY);

	static void parse(Packet* pack, SceneObject* scno);
};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
