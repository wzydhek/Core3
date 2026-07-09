/*
 * ThrowTrapTask.h
 *
 *	Created on: Nov 20, 2010
 *	Author: da
 *
 *	Refactored on: 2024-04-14
 *	By: Hakry
 */

#pragma once

#include "server/zone/objects/creature/CreatureObject.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"
#include "templates/tangible/TrapTemplate.h"
#include "server/zone/objects/creature/buffs/TrapBuff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace events {

class ThrowTrapTask : public Task, public Logger {
	ManagedWeakReference<CreatureObject*> weakAttacker;
	ManagedWeakReference<CreatureObject*> weakTarget;
	ManagedWeakReference<TangibleObject*> weakTrap;

public:
	ThrowTrapTask(CreatureObject* attacker, CreatureObject* target, TangibleObject* trap);

	virtual ~ThrowTrapTask();

	void run();
};

} // namespace events
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::events;
