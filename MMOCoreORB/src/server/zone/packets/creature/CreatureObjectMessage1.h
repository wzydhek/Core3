/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectMessage1 : public BaseLineMessage {
public:
	CreatureObjectMessage1(const CreatureObject* creo);

};
