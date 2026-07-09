/*
 * SecuritySliceTask.h
 *
 *  Created on: Feb 21, 2013
 *      Author: root
 */

#pragma once

#include "server/zone/managers/gcw/GCWManager.h"

class SecuritySliceTask : public Task {

	ManagedReference<TangibleObject*> terminal;
	ManagedReference<GCWManager*> gcwManager;
	ManagedReference<CreatureObject*> creature;

public:

	SecuritySliceTask(GCWManager* gcwMan, TangibleObject* term, CreatureObject* player);

	void run();
};
