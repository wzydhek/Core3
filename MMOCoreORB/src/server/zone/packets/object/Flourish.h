/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class Flourish : public ObjectControllerMessage {
public:
	Flourish(CreatureObject* creo, int flourishid);

};
