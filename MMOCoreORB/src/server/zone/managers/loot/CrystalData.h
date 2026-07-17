#pragma once

#include "engine/engine.h"

namespace server {
namespace zone {
namespace managers {
namespace loot {

class CrystalData : public Object {
	int minDamage;
	int maxDamage;
	int minHitpoints;
	int maxHitpoints;
	int minHealthSac;
	int maxHealthSac;
	int minActionSac;
	int maxActionSac;
	int minMindSac;
	int maxMindSac;
	float minAttackSpeed;
	float maxAttackSpeed;
	float minForceCost;
	float maxForceCost;
	int minWoundChance;
	int maxWoundChance;

public:
	CrystalData();

	CrystalData(const CrystalData& data);

	CrystalData& operator=(const CrystalData& data);

	void readObject(LuaObject* luaObject);

	int getMinDamage() const;

	int getMaxDamage() const;

	int getMinHitpoints() const;

	int getMaxHitpoints() const;

	int getMinHealthSac() const;

	int getMaxHealthSac() const;

	int getMinActionSac() const;

	int getMaxActionSac() const;

	int getMinMindSac() const;

	int getMaxMindSac() const;

	int getMinWoundChance() const;

	float getMinAttackSpeed() const;

	float getMaxAttackSpeed() const;

	float getMinForceCost() const;

	float getMaxForceCost() const;

	int getMaxWoundChance() const;

};

} // namespace loot
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::loot;
