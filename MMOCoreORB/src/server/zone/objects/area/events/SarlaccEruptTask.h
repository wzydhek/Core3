/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "server/zone/Zone.h"
#include "server/zone/objects/area/SarlaccArea.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "templates/params/creature/CreatureAttribute.h"

class SarlaccEruptTask: public Task {
	ManagedReference<SarlaccArea*> sarlaccArea;


public:
	SarlaccEruptTask(SarlaccArea* area);

	void run();
};
