/*
 * CooldownTimerMap.h
 *
 *  Created on: 26/05/2010
 *      Author: victor
 */

#pragma once

#include "engine/engine.h"
#include "engine/util/json_utils.h"

namespace server {
namespace zone {
namespace objects {
namespace creature {
namespace variables {

class CooldownTimer : public Variable {
	Time timeStamp;

public:
	CooldownTimer();

	CooldownTimer(const Time& timestamp);

	CooldownTimer(const CooldownTimer& obj);

	CooldownTimer& operator=(const CooldownTimer& tim);

	void operator=(Time obj);

	bool toString(String& str);

	bool parseFromString(const String& str, int version = 0);

	bool toBinaryStream(ObjectOutputStream* stream);

	friend void to_json(nlohmann::json& j, const CooldownTimer& t);

	bool parseFromBinaryStream(ObjectInputStream* stream);

	bool isPast() const;

	void addMiliTime(uint64 mtime);

	Time* getTime();

	const Time* getTime() const;
};

class CooldownTimerMap : public Object {
	HashTable<String, CooldownTimer> timers;
	mutable Mutex cooldownMutex;

public:
	CooldownTimerMap();

	CooldownTimerMap(const CooldownTimerMap& map);

	~CooldownTimerMap();

	CooldownTimerMap& operator=(const CooldownTimerMap& map);

	bool isPast(const String& cooldownName) const;

	void updateToCurrentAndAddMili(const String& cooldownName, uint64 mili);

	Time* updateToCurrentTime(const String& cooldownName);

	void addMiliTime(const String& cooldownName, uint64 mili);

	const Time* getTime(const String& cooldownName) const;

	Object* clone();

	Object* clone(void* object);
};

void to_json(nlohmann::json& j, const CooldownTimer& t);

} // namespace variables
} // namespace creature
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::creature::variables;
