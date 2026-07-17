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

class SceneObjectDestroyMessage : public BaseMessage {
public:
	SceneObjectDestroyMessage(SceneObject* scno);

	SceneObjectDestroyMessage(uint64 oid);

	SceneObjectDestroyMessage(uint64 oid, bool hyperspace);
};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
