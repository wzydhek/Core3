#pragma once

#include "server/zone/packets/object/ObjectControllerMessageCallback.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class UpdateShipTargetSlotCallback : public MessageCallback {
	int size;
	int targetSlot;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	UpdateShipTargetSlotCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
