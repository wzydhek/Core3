/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace manufactureschematic {

class ManufactureSchematicObjectMessage6 : public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage6(uint64 oid, uint32 schematicCRC, bool activeCraft);
};

} // namespace manufactureschematic
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::manufactureschematic;
