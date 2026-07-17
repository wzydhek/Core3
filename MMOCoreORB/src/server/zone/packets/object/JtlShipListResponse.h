/*
 * JtlShipListResponse.h
 *
 *  Created on: Apr 25, 2011
 *      Author: crush
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class JtlShipListResponse: public ObjectControllerMessage {
public:
	JtlShipListResponse(CreatureObject* player, SceneObject* terminal);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
