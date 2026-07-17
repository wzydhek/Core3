/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/cell/CellObject.h"

namespace server {
namespace zone {
namespace packets {
namespace cell {

class CellObjectDeltaMessage3 : public DeltaMessage {
	CellObject* cell;

public:
	CellObjectDeltaMessage3(CellObject* co);

	void updateCellNumber(int cellNumber);
};

} // namespace cell
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::cell;
