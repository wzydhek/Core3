#include "BoosterOnCommand.h"
#include "server/zone/objects/ship/ShipComponentFlag.h"
#include "server/zone/objects/ship/ComponentSlots.h"
#include "server/zone/objects/ship/ShipComponentFlag.h"

BoosterOnCommand::BoosterOnCommand(const String& name, ZoneProcessServer* server) : QueueCommand(name, server) {
}

int BoosterOnCommand::doQueueCommand(CreatureObject* creature, const uint64& target, const UnicodeString& arguments) const {
	if (!checkStateMask(creature))
		return INVALIDSTATE;

	if (!checkInvalidLocomotions(creature))
		return INVALIDLOCOMOTION;

	if (!creature->isPilotingShip()) {
		return INVALIDSTATE;
	}

	SceneObject* rootParent = creature->getRootParent();

	if (rootParent == nullptr || !rootParent->isShipObject())
		return GENERALERROR;

	ManagedReference<ShipObject*> ship = rootParent->asShipObject();

	if (ship == nullptr || ship->isBoosterActive())
		return GENERALERROR;

	ManagedReference<CreatureObject*> pilot = ship->getPilot();

	if (pilot == nullptr || pilot != creature) {
		creature->sendSystemMessage("@space/space_interaction:booster_pilot_only");
		return GENERALERROR;
	}

	if (!ship->isComponentInstalled(Components::BOOSTER)) {
		creature->sendSystemMessage("@space/space_interaction:no_booster");
		return GENERALERROR;
	}

	if (!ship->isComponentFunctional(Components::BOOSTER)) {
		creature->sendSystemMessage("@space/space_interaction:booster_disabled");
		return GENERALERROR;
	}

	if (!ship->isReadyToBoost()) {
		creature->sendSystemMessage("@space/space_interaction:booster_not_ready");
		return GENERALERROR;
	}

	float boosterEfficiency = Math::clamp(0.1f, ship->getComponentEfficiency(Components::BOOSTER), 10.f);
	float boosterConsumption = ship->getBoosterConsumptionRate() / boosterEfficiency;

	if (ship->getBoosterEnergy() < boosterConsumption) {
		creature->sendSystemMessage("@space/space_interaction:booster_low_energy");
		return GENERALERROR;
	}

	Locker slock(ship, creature);

	ship->addComponentFlag(Components::BOOSTER, ShipComponentFlag::ACTIVE, true);

	return SUCCESS;
}