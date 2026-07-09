#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

class DestroyShipComponentMessage : public BaseMessage {
public:
	DestroyShipComponentMessage(ShipObject* ship, int slot, float scale);
};
