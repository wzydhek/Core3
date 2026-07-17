/*
 * ObjCtrlMessageQueueString.h
 *
 *  Created on: 10/01/2012
 *      Author: victor
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjCtrlMessageQueueString : public ObjectControllerMessage {
public:
	ObjCtrlMessageQueueString(SceneObject* creo, const String& data, uint32 type);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
