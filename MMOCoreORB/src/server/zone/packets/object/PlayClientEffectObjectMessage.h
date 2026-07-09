/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/service/proto/BaseMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class PlayClientEffectObjectMessage : public BaseMessage {
public:
	PlayClientEffectObjectMessage(SceneObject* obj, const String& file, const String& aux);

};
