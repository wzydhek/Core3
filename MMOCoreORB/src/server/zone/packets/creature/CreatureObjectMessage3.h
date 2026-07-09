/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage3.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectMessage3 : public TangibleObjectMessage3 {
public:
	CreatureObjectMessage3(CreatureObject* creo);

};
