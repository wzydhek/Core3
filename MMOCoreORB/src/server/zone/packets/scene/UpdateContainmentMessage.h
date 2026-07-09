/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class UpdateContainmentMessage : public BaseMessage {
public:
	UpdateContainmentMessage(SceneObject* object, SceneObject* container, uint32 type);

	UpdateContainmentMessage(uint64 object, uint64 container, uint32 type);

};
