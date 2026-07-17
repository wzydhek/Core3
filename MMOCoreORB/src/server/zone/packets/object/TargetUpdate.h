/*
 * TargetUpdate.h
 *
 *  Created on: 10/08/2009
 *      Author: victor
 */

#pragma once

#include "../MessageCallback.h"
#include "ObjectControllerMessageCallback.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class TargetUpdateCallback : public MessageCallback {
	int size;
	uint64 targetID;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	TargetUpdateCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();

	void setPlayerTargetID(CreatureObject* object);

	void setShipTargetID(CreatureObject* object);
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
