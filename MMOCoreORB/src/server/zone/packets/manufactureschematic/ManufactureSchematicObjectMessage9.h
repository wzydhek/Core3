/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/BaseLineMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace manufactureschematic {

class ManufactureSchematicObjectMessage9 : public BaseLineMessage {
public:
	ManufactureSchematicObjectMessage9(uint64 oid);
};

} // namespace manufactureschematic
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::manufactureschematic;
