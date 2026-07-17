/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectControllerMessage : public BaseMessage {
public:
	ObjectControllerMessage(uint64 objid, uint32 header1, uint32 header2, bool comp = true);

};

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;
