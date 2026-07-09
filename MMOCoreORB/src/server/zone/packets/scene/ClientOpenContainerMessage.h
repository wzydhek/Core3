/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class ClientOpenContainerMessage : public BaseMessage {
public:
	ClientOpenContainerMessage(SceneObject* container, bool cloose);

	ClientOpenContainerMessage(SceneObject* container);

	ClientOpenContainerMessage(uint64 oid, const String& ascii, int test);
};
