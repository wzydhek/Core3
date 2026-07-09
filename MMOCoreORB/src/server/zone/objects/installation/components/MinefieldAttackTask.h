/*
 * MinefieldAttackTask.h
 *
 *  Created on: 20/12/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"
#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/packets/scene/PlayClientEffectLocMessage.h"
#include "server/zone/objects/creature/commands/CombatQueueCommand.h"
#include "server/zone/objects/installation/components/MinefieldDataComponent.h"
#include "server/zone/objects/installation/components/TurretDataComponent.h"

class MinefieldAttackTask : public Task {
	ManagedWeakReference<TangibleObject*> weakMinefield;
	ManagedWeakReference<CreatureObject*> weakTarget;

public:
	MinefieldAttackTask(TangibleObject* minefield, CreatureObject* creatureTarget);

	void run();
};
