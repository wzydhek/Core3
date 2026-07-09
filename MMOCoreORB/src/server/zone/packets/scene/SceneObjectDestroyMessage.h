/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class SceneObjectDestroyMessage : public BaseMessage {
public:
	SceneObjectDestroyMessage(SceneObject* scno);

	SceneObjectDestroyMessage(uint64 oid);

	SceneObjectDestroyMessage(uint64 oid, bool hyperspace);
};
