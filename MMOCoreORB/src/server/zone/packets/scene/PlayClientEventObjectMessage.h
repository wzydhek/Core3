/*
 * PlayClientEventObjectMessage.h
 *
 *  Created on: 09/01/2012
 *      Author: victor
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace scene {

class PlayClientEventObjectMessage : public BaseMessage {
public:
	PlayClientEventObjectMessage(SceneObject* obj, const String& file, const String& aux);

};

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;
