/*
 * OpenLotteryWindow.h
 *
 *  Created on: Mar 16, 2015
 *      Author: swgemu
 */

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class OpenLotteryWindow : public ObjectControllerMessage {
public:
	OpenLotteryWindow(CreatureObject* creo, SceneObject* inventory);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
