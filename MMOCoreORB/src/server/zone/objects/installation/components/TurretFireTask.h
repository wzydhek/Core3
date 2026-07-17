/*
 * TurretFireTask.h
 *
 *  Created on: 20/12/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/installation/TurretObject.h"
#include "server/zone/managers/collision/CollisionManager.h"
#include "server/zone/objects/creature/commands/CombatQueueCommand.h"
#include "server/zone/managers/combat/CombatManager.h"
#include "server/zone/managers/objectcontroller/ObjectController.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/tangible/terminal/components/TurretControlTerminalDataComponent.h"
#include "TurretDataComponent.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class TurretFireTask : public Task {
	ManagedWeakReference<TurretObject*> weakTurret;
	ManagedWeakReference<TangibleObject*> weakTerminal;
	bool isManual;

public:
	TurretFireTask(TurretObject* turret, TangibleObject* terminal, bool manual);

	void run();

	bool checkTurretController(TurretDataComponent* turretData);

	void closeControls(CreatureObject* controllerCharacter);

	bool checkTarget(TangibleObject* turret, CreatureObject* target);

	bool isManualFireTask();

	void setManualFireTask(bool man);

	void setTerminal(TangibleObject* terminal);
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
