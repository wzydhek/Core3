/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/StandaloneBaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

//#define UNRELIABLE_LIGHT_TRANSFORMS

#ifdef UNRELIABLE_LIGHT_TRANSFORMS
	#define UNRELIABLE_LIGHT_BASE_CLASS StandaloneBaseMessage
#else
	#define UNRELIABLE_LIGHT_BASE_CLASS BaseMessage
#endif

namespace server {
namespace zone {
namespace packets {
namespace scene {

class LightUpdateTransformMessage : public UNRELIABLE_LIGHT_BASE_CLASS {
public:
	LightUpdateTransformMessage(SceneObject* scno);

	LightUpdateTransformMessage(SceneObject* scno, float posX, float posZ, float posY);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
