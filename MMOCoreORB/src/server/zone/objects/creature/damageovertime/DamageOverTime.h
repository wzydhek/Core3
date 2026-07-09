/*
 * DamageOverTime.h
 *
 *  Created on: 04/06/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
class CreatureObject;
}
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature;

class DamageOverTime : public Serializable, public Logger {
protected:
	uint64 attackerID;
	uint64 type;
	uint8 attribute;
	int strength;
	uint32 duration;

	SerializableTime applied;
	SerializableTime expires;
	SerializableTime nextTick;
	int secondaryStrength;

public:
	DamageOverTime();
	DamageOverTime(CreatureObject* attacker, uint64 tp, uint8 attrib, uint32 str, uint32 dur, int secondaryStr = 0);

	DamageOverTime(const DamageOverTime& dot);
	DamageOverTime& operator=(const DamageOverTime& dot);

	void addSerializableVariables();

	/*bool toBinaryStream(ObjectOutputStream* stream);
	bool parseFromBinaryStream(ObjectInputStream* stream);*/

	//~DamageOverTime();

	friend void to_json(nlohmann::json& j, const DamageOverTime& t);

	void activate();
	uint32 applyDot(CreatureObject* victim);
	uint32 initDot(CreatureObject* victim, CreatureObject* attacker);
	float reduceTick(float reduction);

	void expireTick();

	void multiplyDuration(float multiplier);

	// damage methods
	uint32 doBleedingTick(CreatureObject* victim, CreatureObject* attacker);
	uint32 doFireTick(CreatureObject* victim, CreatureObject* attacker);
	uint32 doPoisonTick(CreatureObject* victim, CreatureObject* attacker);
	uint32 doDiseaseTick(CreatureObject* victim, CreatureObject* attacker);
	uint32 doForceChokeTick(CreatureObject* victim, CreatureObject* attacker);

	// Setters
	void setAttackerID(uint64 value);

	void setType(uint64 value);

	void setAttribute(uint8 value);

	void setStrength(uint32 value);

	void setDuration(uint32 seconds);

	void setExpires(const Time& time);

	void setNextTick(const Time& tick);

	void setSecondaryStrength(int str);

	// Getters
	uint64 getAttackerID();

	uint64 getType();

	uint8 getAttribute();

	uint32 getStrength();

	uint32 getDuration();

	bool isActivated();

	bool isPast();

	bool isFuture();

	bool isPresent();

	bool nextTickPast();

	Time getApplied();

	Time getNextTick();

	Time getExpires();

	int getSecondaryStrength();
};
