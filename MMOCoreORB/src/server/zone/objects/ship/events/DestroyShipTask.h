#pragma once

#include "server/zone/SpaceZone.h"
#include "server/zone/objects/ship/ShipObject.h"
#include "server/zone/objects/ship/ComponentSlots.h"
#include "server/zone/objects/ship/ShipComponentFlag.h"
#include "server/zone/managers/space/SpaceManager.h"
#include "server/zone/packets/ship/DestroyShipMessage.h"
#include "server/zone/packets/object/DataTransform.h"
#include "server/zone/objects/intangible/tasks/StoreShipTask.h"
#include "server/zone/packets/ship/ShipObjectMessage3.h"
#include "server/zone/packets/ship/ShipObjectMessage6.h"

class DestroyShipTask: public Task {
private:
	ManagedWeakReference<ShipObject*> weakShip;

	uint64 sequenceStamp;
	int iteration;

public:
	DestroyShipTask(ShipObject* ship);

	void run();
};
