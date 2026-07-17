/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ShowFlyText : public ObjectControllerMessage {
public:
	ShowFlyText(SceneObject* creo, const String& file, const String& aux, uint8 red, uint8 green, uint8 blue, float size);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
