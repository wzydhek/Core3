/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/DeltaMessage.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class ResourceContainerObjectDeltaMessage6 : public DeltaMessage {
public:
	ResourceContainerObjectDeltaMessage6(ResourceContainer* rcno);

	void setResourceName(UnicodeString& resource_name);
	
	void setResourceType(String& resource_type);
	
};
