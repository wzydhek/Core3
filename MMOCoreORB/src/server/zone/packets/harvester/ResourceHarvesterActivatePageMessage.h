/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/


#pragma once

#include "engine/service/proto/BaseMessage.h"

namespace server {
namespace zone {
namespace packets {
namespace harvester {

class ResourceHarvesterActivatePageMessage : public BaseMessage {
public:
	ResourceHarvesterActivatePageMessage(uint64 oid);

};

} // namespace harvester
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::harvester;
