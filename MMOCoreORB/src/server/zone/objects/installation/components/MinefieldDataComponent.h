/*
 * MinefieldDataComponent.h
 *
 *  Created on: Dec 17, 2012
 *      Author: root
 */

#pragma once

#include "engine/engine.h"
#include "server/zone/objects/scene/components/DataObjectComponent.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "templates/installation/SharedInstallationObjectTemplate.h"

namespace server {
namespace zone {
namespace objects {
namespace installation {
namespace components {

class MinefieldDataComponent : public DataObjectComponent {
protected:
	const static int CAPACITY = 20;

	Time explodeDelay;
	float attackSpeed;
	float maxRange;

	Vector<ManagedReference<WeaponObject*>> mines;
	SharedInstallationObjectTemplate* templateData;
	SynchronizedSortedVector<uint64> notifiedPlayers;

public:
	MinefieldDataComponent();

	virtual ~MinefieldDataComponent();

	void writeJSON(nlohmann::json& j) const;

	void initializeTransientMembers();

	bool isMinefieldData();

	bool canExplode();

	int getCapacity();

	void updateCooldown(uint64 cooldown);

	void addMine(WeaponObject* weapon);

	WeaponObject* getMine(int indx);

	WeaponObject* removeMine(int indx);

	int getMineCapacity();

	int getMineCount();

	void setMaxRange(float val);

	float getMaxRange();

	bool hasNotifiedPlayer(const uint64 oid);

	void addNotifiedPlayer(const uint64 oid);

	void removeNotifiedPlayer(const uint64 oid);

private:
	void addSerializableVariables();
};

} // namespace components
} // namespace installation
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::installation::components;
