/*
				Copyright <SWGEmu>
		See file COPYING for copying conditions.*/

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "server/zone/objects/creature/buffs/Buff.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace buffs {

class BuffList : public Serializable {
protected:
	bool spiceActive;
	VectorMap<uint32, ManagedReference<Buff*> > buffList;
	mutable Mutex mutex;

public:
	BuffList();
	BuffList(const BuffList& bf);

	BuffList& operator=(const BuffList& bf);

	void sendTo(CreatureObject* player) const;
	void sendDestroyTo(CreatureObject* player) const;

	void updateBuffsToDatabase();

	void addBuff(Buff* buff);
	bool removeBuff(uint32 buffcrc);
	void removeBuff(Buff* buff);

	void clearBuffs(bool updateclient, bool removeAll);

	int findBuff(Buff* buff) const;

	String getDurationString(bool showhours = true, bool showminutes = true) const;

	friend void to_json(nlohmann::json& j, const BuffList& l);

	//Getters
	int getBuffListSize() const;

	Buff* getBuffByIndex(int index) const;

	Buff* getBuffByCRC(uint32 buffcrc) const;

	long long getModifierByName(const String& skillMod) const;

	bool hasBuff(uint32 buffcrc) const;

	bool hasSpice() const;

	bool hasTrapBuff() const;
};

} // namespace buffs
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::buffs;
