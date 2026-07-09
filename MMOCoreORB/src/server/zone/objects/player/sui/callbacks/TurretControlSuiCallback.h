/*
 * TurretControlSuiCallback.h
 *
 *  Created on: Jan 27, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/objects/player/sui/SuiCallback.h"
#include "server/zone/managers/gcw/GCWManager.h"
#include "server/zone/objects/installation/components/TurretFireTask.h"

class TurretControlSuiCallback : public SuiCallback {
	ManagedWeakReference<TangibleObject*> turretObject;
	ManagedWeakReference<TangibleObject*> turretControl;
public:
	TurretControlSuiCallback(ZoneServer* server, TangibleObject* turret, TangibleObject* terminal);

	void run(CreatureObject* player, SuiBox* suiBox, uint32 eventIndex, Vector<UnicodeString>* args);
};
