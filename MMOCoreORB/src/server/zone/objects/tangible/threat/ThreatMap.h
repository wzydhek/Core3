/*
 * ThreatMap.h
 *
 *  Created on: 13/07/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "ThreatMatrix.h"
#include "server/zone/objects/tangible/threat/ThreatMapObserver.h"
#include "server/zone/objects/creature/variables/CooldownTimerMap.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/ship/ShipObject.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
class CreatureObject;
}
}
}
}

using namespace server::zone::objects::creature;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace threat {

//#define DEBUG

class ThreatMapEntry : public VectorMap<String, uint32> {
	int aggroMod;
	uint64 threatBitmask;
	int healAmount;
	uint32 nonAggroDamageTotal;
	Time startTime;

public:
	ThreatMapEntry();

	ThreatMapEntry(const ThreatMapEntry& e);

	ThreatMapEntry& operator=(const ThreatMapEntry& e);

	void addDamage(WeaponObject* weapon, uint32 damage);
	void addDamage(String xp, uint32 damage);

	void setThreatState(uint64 state);
	bool hasState(uint64 state);
	void clearThreatState(uint64 state);

	void addAggro(int value);

	void addHeal(int value);

	int getHeal();

	int getAggroMod();

	uint32 getDurationSeconds();

	uint32 getDPS();

	void removeAggro(int value);

	void clearAggro();

	uint32 getTotalDamage();

	// getLootDamage excludes damage done by DOT's
	uint32 getLootDamage();

	void setNonAggroDamage(uint32 amount);

	uint32 getNonAggroDamage();
};

class ThreatMap : public VectorMap<ManagedReference<TangibleObject*>, ThreatMapEntry>, public Logger {
public:
	/// Time between normal target evaluation
	enum { EVALUATIONCOOLDOWN = 24000 };

protected:
	ManagedWeakReference<TangibleObject*> self;
	CooldownTimerMap cooldownTimerMap;
	ManagedWeakReference<TangibleObject*> currentThreat;
	ThreatMatrix threatMatrix;
	ManagedReference<ThreatMapObserver*> threatMapObserver;
	Mutex lockMutex;

public:
	ThreatMap(TangibleObject* me);

	ThreatMap(const ThreatMap& map);

	ThreatMap& operator=(const ThreatMap& map);

	~ThreatMap();

	void removeAll(bool forceRemoveAll = false);

	void removeObservers();

	void addDamage(TangibleObject* target, uint32 damage, String xp = "");
	void dropDamage(TangibleObject* target);

	bool setThreatState(TangibleObject* target, uint64 state, uint64 duration = 0, uint64 cooldown = 0);
	void clearThreatState(TangibleObject* target, uint64 state);

	bool hasState(uint64 state);
	bool isUniqueState(uint64 state);

	CreatureObject* getHighestDamagePlayer();
	CreatureObject* getHighestDamageGroupLeader();

	ShipObject* getHighestDamagePlayerShip();
	ShipObject* getHighestDamageGroupShip();

	TangibleObject* getHighestThreatAttacker();
	uint32 getTotalDamage();

	void addAggro(TangibleObject* target, int value, uint64 duration = 0);
	void removeAggro(TangibleObject* target, int value);
	void clearAggro(TangibleObject* target);

	void addHeal(TangibleObject* target, int value);

private:
	void registerObserver(TangibleObject* target);
};
}
}
}
}
}

using namespace server::zone::objects::tangible::threat;
