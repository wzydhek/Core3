/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace cell {

class CellObjectMessage6 : public BaseLineMessage {
public:
	CellObjectMessage6(uint64 coId);
};

} // namespace cell
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::cell;
