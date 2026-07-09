/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "StandaloneObjectControllerMessage.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

class CombatSpam : public StandaloneObjectControllerMessage {
public:

	CombatSpam(TangibleObject* attacker, TangibleObject* defender, CreatureObject* receiver, TangibleObject* item, uint32 damage, const String& file, const String& stringName, byte color);

	//For custom combat spam messages.
	CombatSpam(CreatureObject* receiver, const UnicodeString& uniString, byte color);

};
