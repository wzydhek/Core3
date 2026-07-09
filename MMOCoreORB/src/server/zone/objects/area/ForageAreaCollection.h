/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "ForageArea.h"
#include "server/zone/managers/minigames/events/ForageCleanupEvent.h"
#include "server/zone/objects/creature/CreatureObject.h"

class ForageAreaCollection : public Object {

protected:

	Vector<Reference<ForageArea*> > forageAreas;
	Reference<Task*> cleanupEvent;


public:
	ForageAreaCollection(CreatureObject* player, short forageX, short forageY, const String& planet, int forageAreaType);


	bool checkForageAreas(short forageX, short forageY, const String& planet, int forageAreaType);

};
