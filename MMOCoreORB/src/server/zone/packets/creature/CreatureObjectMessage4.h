/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectMessage4 : public BaseLineMessage {
public:
	CreatureObjectMessage4(CreatureObject* creo);
};
