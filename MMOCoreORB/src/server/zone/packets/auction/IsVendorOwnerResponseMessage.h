/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

class IsVendorOwnerResponseMessage : public BaseMessage {

public:
	IsVendorOwnerResponseMessage(SceneObject* vendor, CreatureObject* player, const String& planet, const String& region);

};
