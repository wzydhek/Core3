/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class ResourceContainerObjectDeltaMessage3 : public DeltaMessage {
private:
	ManagedReference<ResourceContainer*> container;

public:
	ResourceContainerObjectDeltaMessage3(ResourceContainer* rcno);
		
	void updateQuantity();
	
};
