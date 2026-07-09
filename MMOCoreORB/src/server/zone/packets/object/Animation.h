/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class Animation : public ObjectControllerMessage {
public:
	Animation(CreatureObject* creo, const String& anim);

};
