/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace cell {

class CellObjectMessage3 : public BaseLineMessage {
public:
	CellObjectMessage3(uint64 coId, int cellNumber);
};

} // namespace cell
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::cell;
