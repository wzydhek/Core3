/*
 				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

/**
 * SpawnHelperDroidTask.h
 *
 *  Created: Monday May 9, 2022
 *   Author: H
 *
 */

#pragma once

#include "server/zone/ZoneServer.h"
#include "server/zone/objects/scene/SceneObject.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/objects/creature/ai/HelperDroidObject.h"
#include "server/zone/managers/creature/CreatureTemplateManager.h"
#include "server/zone/objects/creature/ai/CreatureTemplate.h"
#include "server/zone/managers/creature/CreatureManager.h"
#include "server/zone/managers/creature/PetManager.h"
#include "server/zone/objects/intangible/PetControlDevice.h"
#include "server/zone/managers/stringid/StringIdManager.h"

class SpawnHelperDroidTask: public Task {
	ManagedWeakReference<CreatureObject*> player;

public:
	SpawnHelperDroidTask(CreatureObject* creature);

	void run();
};
