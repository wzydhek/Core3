/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/resource/ResourceContainer.h"

namespace server {
namespace zone {
namespace packets {
namespace resource {

class ResourceContainerObjectDeltaMessage6 : public DeltaMessage {
public:
	ResourceContainerObjectDeltaMessage6(ResourceContainer* rcno);

	void setResourceName(UnicodeString& resource_name);
	
	void setResourceType(String& resource_type);
	
};

} // namespace resource
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::resource;
