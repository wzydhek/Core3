
#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"

class FindObjectSuiCallback : public SuiCallback {

public:
	FindObjectSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
