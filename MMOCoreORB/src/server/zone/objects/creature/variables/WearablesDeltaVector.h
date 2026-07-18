/*
 * WearablesDeltaVector.h
 *
 *  Created on: 09/04/2012
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/scene/variables/DeltaVector.h"
#include "server/zone/objects/tangible/TangibleObject.h"
#include "server/zone/objects/tangible/wearables/ArmorObject.h"
#include "templates/tangible/ArmorObjectTemplate.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

class WearablesDeltaVector : public DeltaVector<ManagedReference<TangibleObject*> > {
private:
	// note: duplicate of CombatManager::hitlocations.
	enum HitLocation : int {
		HIT_BODY = 0,
		HIT_HEAD = 1,
		HIT_RARM = 2,
		HIT_LARM = 3,
		HIT_RLEG = 4,
		HIT_LLEG = 5,
		HIT_NUM = 6,
	};

protected:
	VectorMap<uint8, Vector<ManagedReference<ArmorObject*> > > protectionArmorMap;

public:

	WearablesDeltaVector();

	bool readObjectMember(ObjectInputStream* stream, const String& name);

	int writeObjectMembers(ObjectOutputStream* stream);

	friend void to_json(nlohmann::json& j, const WearablesDeltaVector& vec);

	bool toBinaryStream(ObjectOutputStream* stream) override;

	bool parseFromBinaryStream(ObjectInputStream* stream) override;

	void insertItemToMessage(ManagedReference<TangibleObject*>* item, BaseMessage* msg) const override;

	bool add(const ManagedReference<TangibleObject*>& element, DeltaMessage* message = nullptr, int updates = 1) override;

	ManagedReference<TangibleObject*> remove(int index, DeltaMessage* message = nullptr, int updates = 1) override;


	Vector<ManagedReference<ArmorObject*>> getArmorAtHitLocation(uint8 hitLocation) const;

	void addArmor(uint8 hitLocation, ManagedReference<ArmorObject*> armor);

	void removeArmor(uint8 hitLocation, ManagedReference<ArmorObject*> armor);
};

void to_json(nlohmann::json& j, const WearablesDeltaVector& vec);

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;
