/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/resource/ResourceContainer.h"

namespace server {
namespace zone {
namespace packets {
namespace resource {

class ResourceContainerObjectMessage6 : public BaseLineMessage {
public:
	ResourceContainerObjectMessage6(ResourceContainer* rcno);
};

} // namespace resource
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::resource;
