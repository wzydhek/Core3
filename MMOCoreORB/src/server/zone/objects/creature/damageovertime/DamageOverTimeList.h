/*
 * DamageOverTimeList.h
 *
 *  Created on: 04/06/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"
#include "DamageOverTime.h"

class DamageOverTimeList : private VectorMap<uint64, Vector<DamageOverTime>>, public Logger {
protected:
	Time nextTick;
	Mutex guard;

public:
	DamageOverTimeList();

	DamageOverTimeList(const DamageOverTimeList& list);

	DamageOverTimeList& operator=(const DamageOverTimeList& list);

	friend void to_json(nlohmann::json& j, const DamageOverTimeList& l);

	bool toBinaryStream(ObjectOutputStream* stream);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	uint64 activateDots(CreatureObject* victim);
	uint32 addDot(CreatureObject* victim, CreatureObject* attacker, uint64 parentObjectID, uint32 duration, uint64 dotType, uint8 pool, uint32 strength, float potency, uint32 defense, int secondaryStrength = 0);
	uint8 getRandomPool(uint64 dotType);
	bool healState(CreatureObject* victim, uint64 dotType, float reduction, bool sendMsg = true);
	void clear(CreatureObject* creature);
	void validateDots(CreatureObject* creature);
	bool hasDot(uint64 dotType);
	void multiplyAllDOTDurations(float multiplier);

	void sendStartMessage(CreatureObject* victim, uint64 type);
	void sendStopMessage(CreatureObject* victim, uint64 type);
	void sendIncreaseMessage(CreatureObject* victim, uint64 type);
	void sendDecreaseMessage(CreatureObject* victim, uint64 type);

	int getStrength(uint8 pool, uint64 dotType);

	uint64 generateKey(uint64 dotType, uint8 pool, uint64 parentObjectID);

	void setNextTick(Time time);

	void setNextTick(uint32 delay);

	Time getNextTick();

	bool hasDot();

	bool isNextTickPast();
};
