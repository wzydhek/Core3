#pragma once

#include "server/zone/objects/creature/ai/DroidObject.h"

namespace server {
namespace zone {
namespace managers {
namespace crafting {
namespace labratories {

class DroidMechanics {
public:
	static float determineHam(float quality, int droidType);
	static float determineSpeed(int droidType, float ham);
	static float determineHit(int droidType, float ham);
	static float determineMinDamage(int droidType, int rating);
	static float determineMaxDamage(int droidType, int rating);
	/** Used to determine harvest droid and trap droid skill mod*/
	static int determineDroidSkillBonus(float playerSkill, float droidSkill, float baseAmount);
};

}
}
}
}
}

using namespace server::zone::managers::crafting::labratories;
