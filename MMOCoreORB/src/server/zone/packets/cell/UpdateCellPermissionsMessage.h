/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace cell {

class UpdateCellPermissionsMessage : public BaseMessage {
public:
	UpdateCellPermissionsMessage(uint64 coId, bool allowEntry = true);
};

} // namespace cell
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::cell;
