
#pragma once

#include "templates/params/primitives/StringParam.h"

namespace server {
namespace zone {
namespace managers {
namespace creature {

class MountSpeedData : public Object {

protected:
	StringParam appearanceFilename;
	float runSpeed;
	float gallopSpeedMultiplier;
	int gallopDuration;
	int gallopCooldown;

public:
	MountSpeedData(String file, float run, float multiplier, int duration, int cooldown);

	~MountSpeedData();

	String getAppearanceFilename();

	float getRunSpeed();

	float getGallopSpeedMultiplier();

	int getGallopDuration();

	int getGallopCooldown();
};

}
}
}
}

using namespace server::zone::managers::creature;