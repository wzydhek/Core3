/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class SceneObjectCloseMessage : public BaseMessage {
public:
	SceneObjectCloseMessage(const SceneObject* scno);

	SceneObjectCloseMessage(uint64 oid);

};
