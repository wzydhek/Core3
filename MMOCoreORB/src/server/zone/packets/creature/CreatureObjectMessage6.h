/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "server/zone/packets/tangible/TangibleObjectMessage6.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CreatureObjectMessage6 : public TangibleObjectMessage6 {
public:
	CreatureObjectMessage6(const CreatureObject* creo);

	void insertEquipmentList(const CreatureObject* creo);
};
