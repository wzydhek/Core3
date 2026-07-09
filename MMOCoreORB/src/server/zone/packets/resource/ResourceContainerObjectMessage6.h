/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class ResourceContainerObjectMessage6 : public BaseLineMessage {
public:
	ResourceContainerObjectMessage6(ResourceContainer* rcno);
};
