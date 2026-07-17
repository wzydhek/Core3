/*
DefenderHitList.h

Author: Hakry
*/

#pragma once

#include "server/zone/objects/tangible/TangibleObject.h"

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace managers {
namespace combat {

class DefenderHitList : public Object {
	ManagedWeakReference<TangibleObject*> defender;
	int hit;
	uint8 hitLocation;
	uint32 animationCRC;
	int initialDamage;
	float damageMultiplier;
	int foodMitigation;
	int jediMitigation;
	int forceFeedback;
	int forceAbsorb;
	int psgMitigation;
	int armorMitigation;
	Vector<int> poolsToWound;

public:
	DefenderHitList();

	~DefenderHitList();

	void setDefender(TangibleObject* tano);

	void setHit(int val);

	void setHitLocation(int val);

	void setAnimationCRC(uint32 val);

	void setInitialDamage(int initDam);

	void setDamageMultiplier(float damageMulti);

	void setFoodMitigation(int fMit);

	void setJediMitigation(int jediArmMit);

	void setForceFeedback(int feedbackDam);

	void setForceAbsorb(int amountAbsorbed);

	void setPsgMitigation(int psgMit);

	void setArmorMitigation(int armorMit);

	void setPoolsToWound(const Vector<int>& woundPools);

	ManagedReference<TangibleObject*> getDefender();

	int getHit();

	int getHitLocation();

	uint32 getAnimationCRC();

	int getInitialDamage();

	float getDamageMultiplier();

	int getFoodMitigation();

	int getJediMitigation();

	int getForceFeedback();

	int getForceAbsorb();

	int getPsgMitigation();

	int getArmorMitigation();

	const Vector<int>& getPoolsToWound();
};

} // namespace combat
} // namespace managers
} // namespace zone
} // namespace server

using namespace server::zone::managers::combat;
