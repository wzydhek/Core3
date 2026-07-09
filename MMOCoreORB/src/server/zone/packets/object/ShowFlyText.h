/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/scene/SceneObject.h"

class ShowFlyText : public ObjectControllerMessage {
public:
	ShowFlyText(SceneObject* creo, const String& file, const String& aux, uint8 red, uint8 green, uint8 blue, float size);

};
