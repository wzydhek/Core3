/*
 * GotoSuiCallback.h
 *
 * Created: Sun Feb 28 07:01:21 EST 2016
 *  Author: lordkator
 */

#pragma once

#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/objects/waypoint/WaypointObject.h"

class GotoSuiCallback : public SuiCallback {

public:
	GotoSuiCallback(ZoneServer* serv);

	void run(CreatureObject* creature, SuiBox* sui, uint32 eventIndex, Vector<UnicodeString>* args);
};
