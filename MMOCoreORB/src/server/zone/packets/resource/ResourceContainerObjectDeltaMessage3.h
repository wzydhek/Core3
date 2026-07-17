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

class ResourceContainerObjectDeltaMessage3 : public DeltaMessage {
private:
	ManagedReference<ResourceContainer*> container;

public:
	ResourceContainerObjectDeltaMessage3(ResourceContainer* rcno);
		
	void updateQuantity();
	
};

} // namespace resource
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::resource;
