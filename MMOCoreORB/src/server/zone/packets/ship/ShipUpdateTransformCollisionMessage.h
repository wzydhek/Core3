/*
 * ShipUpdateTransformCollisionMessage.h
 *
 *  Created on: 01/09/2011
 *      Author: TheAnswer
 */

#pragma once

#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class ShipUpdateTransformCollisionMessage : public BaseMessage {
public:
	ShipUpdateTransformCollisionMessage(SceneObject* scno);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
