/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ObjectControllerMessage.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

using server::zone::objects::tangible::weapon::WeaponObject;

class WeaponRanges : public ObjectControllerMessage {
public:
	WeaponRanges(CreatureObject* creo, WeaponObject* weao);

};
