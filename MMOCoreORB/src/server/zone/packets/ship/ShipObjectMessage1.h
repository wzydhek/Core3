/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions. */

#pragma once

#include "server/zone/packets/BaseLineMessage.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace packets {
namespace ship {

class ShipObjectMessage1 : public BaseLineMessage {
protected:
	enum index : int {
		serverObjectsStart = 0,
		serverObjectsEnd = 1,
		componentEfficiencyMap = 2,
		componentEnergyEfficiencyMap = 3,
		componentEnergyCostMap = 4,
		componentMassMap = 5,
		componentNameMap = 6,
		componentCreatorMap = 7,
		componentMaxDamageMap = 8,
		componentMinDamageMap = 9,
		componentshieldEffectivenessMap = 10,
		componentarmorEffectivenessMap = 11,
		componentenergyPerShotMap = 12,
		componentRefireRate = 13,
		componentcurrentAmmoMap = 14,
		componentmaxAmmoMap = 15,
		componentammoClassMap = 16,
		chassisMaxMass = 17,
		shieldRechargeRate = 18,
		capacitorMaxEnergy = 19,
		capacitorRechargeRate = 20,
		engineAccelerationRate = 21,
		engineDecelerationRate = 22,
		enginePitchAccelerationRate = 23,
		engineYawAccelerationRate = 24,
		engineRollAccelerationRate = 25,
		enginePitchRateMaximum = 26,
		engineYawRateMaximum = 27,
		engineRollRateMaximum = 28,
		engineSpeedMaximum = 29,
		reactorGenerationRate = 30,
		boosterMaxEnergy = 31,
		boosterRechargeRate = 32,
		boosterConsumptionRate = 33,
		boosterAcceleration = 34,
		boosterMaxSpeed = 35,
		droidCommandSpeed = 36,
		droidObjectID = 37,
	};

public:
	ShipObjectMessage1(ShipObject* ship);
};

} // namespace ship
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::ship;
