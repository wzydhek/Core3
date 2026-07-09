/*
 * PlayerTeachConfirmSuiCallback.h
 *
 *  Created on: Mar 13, 2012
 *      Author: katherine
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/creature/variables/Skill.h"

class PlayerTeachConfirmSuiCallback: public SuiCallback {
	WeakReference<Skill*> skill;

public:
	PlayerTeachConfirmSuiCallback(ZoneServer* serv, Skill* skl);

	void run(CreatureObject* student, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
