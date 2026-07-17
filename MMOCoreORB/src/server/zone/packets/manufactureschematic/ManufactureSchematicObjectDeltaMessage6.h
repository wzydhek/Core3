/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

namespace server {
namespace zone {
namespace packets {
namespace manufactureschematic {

class ManufactureSchematicObjectDeltaMessage6 : public DeltaMessage {
public:
	ManufactureSchematicObjectDeltaMessage6(SceneObject* schematic);
	
	void insertToResourceSlot(int slotNumber);
};

} // namespace manufactureschematic
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::manufactureschematic;
