/*
 * TurretDataComponent.h
 *
 *  Created on: Nov 24, 2012
 *      Author: root
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "templates/installation/SharedInstallationObjectTemplate.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/objects/creature/CreatureObject.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class TurretDataComponent : public DataObjectComponent {
protected:
	float maxRange;
	float attackSpeed;

	Time nextAutoFireTime;

	SharedInstallationObjectTemplate* templateData;

	ManagedWeakReference<CreatureObject*> controller;
	ManagedWeakReference<CreatureObject*> manualTarget;
	ManagedWeakReference<CreatureObject*> lastAutoTarget;

	Reference<Task*> turretTask;
	AtomicInteger numberOfPlayersInRange;

	float maxMineRange;
	Time explodeDelay;

	Vector<ManagedReference<WeaponObject*>> mines;
	SynchronizedSortedVector<uint64> notifiedPlayers;

public:
	TurretDataComponent();

	~TurretDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void initializeTransientMembers();
	void fillAttributeList(AttributeListMessage* alm);

	Vector<CreatureObject*> getAvailableTargets(bool aggroOnly);
	CreatureObject* selectTarget();
	bool checkTarget(CreatureObject* creature, TangibleObject* turret, bool aggroOnly);

	void updateAutoCooldown(float secondsToAdd);

	void scheduleFireTask(CreatureObject* target, TangibleObject* terminal, int delay = 0);
	void rescheduleFireTask(bool wasManual, bool isManual);
	int getAutoFireTimeout();

	/*
	 * Setters
	 */

	void setController(CreatureObject* creature);

	void setManualTarget(CreatureObject* creature);

	uint32 incrementNumberOfPlayersInRange();

	uint32 decrementNumberOfPlayersInRange();

	void addNotifiedPlayer(const uint64 oid);

	void removeNotifiedPlayer(const uint64 oid);

	void updateMineCooldown(uint64 cooldown);

	/*
	 * Getters
	 */

	int getRescheduleDelay();

	CreatureObject* getController();

	CreatureObject* getManualTarget();

	int getMaxRange();

	float getAttackSpeed();

	Task* getFireTask();

	uint32 getNumberOfPlayersInRange();

	int getMineCount();

	float getMaxMineRange();

	bool compareAndSetNumberOfPlayersInRange(uint32 oldVal, uint32 newVal);

	bool canExplodeMine();

	bool isTurretData();

	bool hasNotifiedPlayer(const uint64 oid);

private:
	void addSerializableVariables();
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
