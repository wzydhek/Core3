#include "ShipObjectMessage1.h"

ShipObjectMessage1::ShipObjectMessage1(ShipObject* ship) : BaseLineMessage(ship->getObjectID(), 0x53484950, 1, 38) {
	insertInt(0); // start ServerObject
	insertInt(0); // EndServerObject

	ship->getComponentEfficiencyMap()->insertToMessage(this);
	ship->getComponentEnergyEfficiencyMap()->insertToMessage(this);
	ship->getComponentEnergyCostMap()->insertToMessage(this);
	ship->getComponentMassMap()->insertToMessage(this);
	ship->getComponentNameMap()->insertToMessage(this);
	ship->getComponentCreatorMap()->insertToMessage(this);
	ship->getComponentMaxDamageMap()->insertToMessage(this);
	ship->getComponentMinDamageMap()->insertToMessage(this);
	ship->getShieldEffectivenessMap()->insertToMessage(this);
	ship->getArmorEffectivenessMap()->insertToMessage(this);
	ship->getEnergyPerShotMap()->insertToMessage(this);
	ship->getComponentRefireRate()->insertToMessage(this);
	ship->getCurrentAmmoMap()->insertToMessage(this);
	ship->getMaxAmmoMap()->insertToMessage(this);
	ship->getAmmoClassMap()->insertToMessage(this);

	insertFloat(ship->getChassisMaxMass());
	insertFloat(ship->getShieldRechargeRate());
	insertFloat(ship->getCapacitorMaxEnergy());
	insertFloat(ship->getCapacitorRechargeRate());

	insertFloat(ship->getEngineAccelerationRate());
	insertFloat(ship->getEngineDecelerationRate());
	insertFloat(ship->getEnginePitchAccelerationRate());
	insertFloat(ship->getEngineYawAccelerationRate());
	insertFloat(ship->getEngineRollAccelerationRate());
	insertFloat(ship->getEnginePitchRate());
	insertFloat(ship->getEngineYawRate());
	insertFloat(ship->getEngineRollRate());
	insertFloat(ship->getEngineMaxSpeed());

	insertFloat(ship->getReactorGenerationRate());
	insertFloat(ship->getBoosterMaxEnergy());
	insertFloat(ship->getBoosterRechargeRate());
	insertFloat(ship->getBoosterConsumptionRate());
	insertFloat(ship->getBoosterAcceleration());
	insertFloat(ship->getBoosterMaxSpeed());

	insertFloat(ship->getDroidCommandSpeed());
	insertLong(ship->getShipDroidID());

	setSize();
}