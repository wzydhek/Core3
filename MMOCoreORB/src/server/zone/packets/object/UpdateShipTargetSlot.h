#pragma once

#include "server/zone/packets/object/ObjectControllerMessageCallback.h"

class UpdateShipTargetSlotCallback : public MessageCallback {
	int size;
	int targetSlot;

	ObjectControllerMessageCallback* objectControllerMain;
public:
	UpdateShipTargetSlotCallback(ObjectControllerMessageCallback* objectControllerCallback);

	void parse(Message* message);

	void run();
};
