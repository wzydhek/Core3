/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/resource/ResourceContainer.h"

class ResourceContainerObjectMessage3 : public TangibleObjectMessage3 {
public:
	ResourceContainerObjectMessage3(ResourceContainer* rcno);
};
