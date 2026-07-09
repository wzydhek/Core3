/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class UpdateTransformMessage : public BaseMessage {
public:
	UpdateTransformMessage(SceneObject* scno);

	UpdateTransformMessage(SceneObject* scno, float posX, float posZ, float posY);

	static void parse(Packet* pack, SceneObject* scno);
};
