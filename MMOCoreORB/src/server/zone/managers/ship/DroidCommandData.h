
#pragma once

#include "system/lang/Object.h"
#include "system/lang/String.h"

namespace server {
namespace zone {
namespace managers {
namespace ship {

class DroidCommandData : public Object {

protected:
	String commandName;
	String stringID;
	float delayModifier;
	int componentType;
	float energyEfficiency;
	float generalEfficiency;
	float damage;
	float frontReinforceRatio;
	float capacitorReinforcePercentage;
	float frontShieldRatio;

public:
	DroidCommandData(String command, String notifyString, float delay, int component, float energyModifier, float generalModifier, float incurDamage, float frontReinforcePercent, float capacitorReinforcePercent, float frontRatio);

	~DroidCommandData();

	const String& getCommandName() const;

	const String& getStringID() const;

	float getDelayModifier() const;

	int getComponentType() const;

	float getEnergyEfficiency() const;

	float getGeneralEfficiency() const;

	float getDamage() const;

	float getFrontReinforceRatio() const;

	float getCapacitorReinforcePercentage() const;

	float getFrontShieldRatio() const;
};

}
}
}
}

using namespace server::zone::managers::ship;
