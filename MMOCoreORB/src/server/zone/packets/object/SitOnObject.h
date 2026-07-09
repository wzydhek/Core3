/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class SitOnObject : public ObjectControllerMessage {
public:
	SitOnObject(CreatureObject* creo, float x, float y, float z);
	
};
