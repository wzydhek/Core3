/*
 * ClientMfdStatusUpdateMessage.h
 *
 *  Created on: Nov 24, 2008
 *      Author: swgemu
 */

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace ui {

class ClientMfdStatusUpdateMessage : public BaseMessage {

public:
	ClientMfdStatusUpdateMessage();

	ClientMfdStatusUpdateMessage(SceneObject* sceno);

	ClientMfdStatusUpdateMessage(SceneObject* sceno, const String& planet);

	void UpdateMember(SceneObject* cr, const String& planet);
};

} // namespace ui
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ui;
